#include "fileview.h"
#include <QStringList>
#include <QIcon>
FileView::FileView(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("File View"));
    fileLineEdit = new QLineEdit(tr("/"));
    fileListWidget = new QListWidget;
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);
    connect(fileLineEdit,SIGNAL(returnPressed()),this,SLOT (slotShow (QDir)));
    connect(fileListWidget,SIGNAL(itemDoubleClicked (QListWidgetItem*)),
            this,SLOT(slotDirShow(QListWidgetItem*)));
    QString root = "/";
    QDir rootDir(root);
    QStringList string;
    string << "*";
    QFileInfoList list=rootDir.entryInfoList(string);
    showFileInfoList(list);
}

void FileView::slotShow(QDir dir)
{
    QStringList string;
    string<<"*";
    QFileInfoList list=dir.entryInfoList(string,QDir::AllEntries,QDir:: DirsFirst);										//(a)
    showFileInfoList(list);
}

void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();					//首先清空列表控件
    for(unsigned int i=0;i<list.count();i++)	//(a)
    {
        QFileInfo tmpFileInfo=list.at(i);
        if(tmpFileInfo.isDir())
        {
            QIcon icon("dir.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }
        else if(tmpFileInfo.isFile())
        {
            QIcon icon("file.png");
            QString fileName=tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }
    }
}

void FileView::slotDirShow(QListWidgetItem * item)
{
    QString str=item->text();			//将下一级的目录名保存在str中
    QDir dir;							//定义一个QDir对象
    dir.setPath(fileLineEdit->text());  //设置QDir对象的路径为当前目录路径
    dir.cd(str);                        //根据下一级目录名重新设置QDir对象的路径
    fileLineEdit->setText(dir.absolutePath());	//(a)
    slotShow(dir);						//显示当前目录下的所有文件
}

FileView::~FileView()
{

}
