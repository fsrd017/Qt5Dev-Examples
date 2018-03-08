#include "progressdlg.h"
#include <QProgressDialog>
#include <QFont>
ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    setWindowTitle(tr("Progress"));
    FileNum =new QLabel;
    FileNum->setText(tr("文件数目："));
    FileNumLineEdit =new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));
    ProgressType =new QLabel;
    ProgressType->setText(tr("显示类型："));
    comboBox =new QComboBox;
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));
    progressBar =new QProgressBar;
    starBtn =new QPushButton();
    starBtn->setText(tr("开始"));
    mainLayout =new QGridLayout(this);
    mainLayout->addWidget(FileNum,0,0);
    mainLayout->addWidget(FileNumLineEdit,0,1);
    mainLayout->addWidget(ProgressType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(starBtn,3,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    connect(starBtn,SIGNAL(clicked()),this,SLOT(startProgress()));
}

void ProgressDlg::startProgress()
{
    bool ok;
    int num =FileNumLineEdit->text().toInt(&ok);//(a)
    if(comboBox->currentIndex()==0)     	//采用进度条的方式显示进度
    {
        progressBar->setRange(0,num);		//(b)
        for(int i=1;i<num+1;i++)
        {
            progressBar->setValue(i);		//(c)
        }
    }
    else if(comboBox->currentIndex()==1)	//采用进度对话框显示进度
    {
        //创建一个进度对话框
        QProgressDialog *progressDialog=new QProgressDialog(this);
        QFont font("ZYSong18030",12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);     //(d)
        progressDialog->setMinimumDuration(5);					//(e)
        progressDialog->setWindowTitle(tr("Please Wait"));		//(f)
        progressDialog->setLabelText(tr("Copying..."));         //(g)
        progressDialog->setCancelButtonText(tr("Cancel"));		//(h)
        progressDialog->setRange(0,num);	  //设置进度对话框的步进范围
        for(int i=1;i<num+1;i++)
        {
            progressDialog->setValue(i);						//(i)
            if(progressDialog->wasCanceled())					//(j)
                return;
        }
    }
}

ProgressDlg::~ProgressDlg()
{

}
