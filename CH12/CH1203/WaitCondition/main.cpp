#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <stdio.h>
const int DataSize=1000;
const int BufferSize=80;
int buffer[BufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;								//(a)
int numUsedBytes=0;							//(b)
int rIndex=0;								//(c)
class Producer : public QThread
{
public:
    Producer();
    void run();
};
Producer::Producer()
{
}
void Producer::run()
{
    for(int i=0;i<DataSize;i++)				//(a)
    {
       mutex.lock();
       if(numUsedBytes==BufferSize)			//(b)
          bufferEmpty.wait(&mutex);			//(c)
       buffer[i%BufferSize]=numUsedBytes;	//(d)
       ++numUsedBytes;						//增加numUsedBytes变量
       bufferFull.wakeAll();				//(e)
       mutex.unlock();
    }
}
class Consumer : public QThread
{
public:
    Consumer();
    void run();
};
Consumer::Consumer()
{
}
void Consumer::run()
{
    forever
    {
        mutex.lock();
        if(numUsedBytes==0)
            bufferFull.wait(&mutex);			//(a)
        printf("%ul::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
                                                //(b)
        rIndex=(++rIndex)%BufferSize;			//将rIndex变量循环加1
        --numUsedBytes;							//(c)
        bufferEmpty.wakeAll();					//(d)
        mutex.unlock();
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
    Consumer consumerA;
    Consumer consumerB;
    producer.start();
    consumerA.start();
    consumerB.start();
    producer.wait();
    consumerA.wait();
    consumerB.wait();
    return a.exec();
}
