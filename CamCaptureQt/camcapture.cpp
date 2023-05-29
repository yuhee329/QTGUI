#include "camcapture.h"
#include "ui_camcapture.h"

CamCapture::CamCapture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CamCapture)
{
    ui->setupUi(this);
    ui->pPBSnapShot->setEnabled(false);
    camViewFlag = false;
    cnt = 0;
//    CamView();
    connect(ui->pPBCamPlay,SIGNAL(clicked(bool)),this,SLOT(camPlay(bool)));
    connect(ui->pPBSnapShot,SIGNAL(clicked()),this,SLOT(snapShot()));
}

CamCapture::~CamCapture()
{
    delete ui;
}

void CamCapture::CamView()
{
    VideoCapture  capture(0);
    if (!capture.isOpened())
    {
        cout << "카메라가 연결되지 않았습니다." << endl;
        exit(1);
    }
    capture.set(CAP_PROP_FRAME_WIDTH,640);
    capture.set(CAP_PROP_FRAME_HEIGHT,480);
//  capture.set(CAP_PROP_FPS,30);
    cout << "너비 " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << "높이 " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cout << "노출 " << capture.get(CAP_PROP_EXPOSURE) << endl;
    cout << "밝기 " << capture.get(CAP_PROP_BRIGHTNESS) << endl;

    while(camViewFlag) {
//      tm.start();

        capture.read(frame);

        put_string(frame, "Count: ", Point(10, 40), cnt);
        fname = "cam_" + to_string(cnt++);
        fname += ".jpg";

        QImage _img(frame.data,frame.cols,frame.rows,QImage::Format_BGR888);
        ui->pLabelCamView->setPixmap(QPixmap::fromImage(_img));
        this->show();
//        imshow("카메라 영상보기", frame);
        waitKey(33);
/*        int key = waitKey(33);
        if(key == 's') //115
            imwrite(fname,frame);
        else if(key == 'b')  //98
        {
            cout << "key : " << key << endl;
            break;
        }
*/
    }
    capture.release();
}
void CamCapture::put_string(Mat &frame, string text, Point pt, int value)
{
    text += to_string(value);
    Point shade = pt + Point(2, 2);
    int font = FONT_HERSHEY_SIMPLEX;
    putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);     // 그림자 효>과
    putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);// 작성 문자
}
void CamCapture::camPlay(bool bCheck)
{
    if(bCheck)
    {
        camViewFlag = true;
        ui->pPBCamPlay->setText("camera stop");
        ui->pPBSnapShot->setEnabled(true);
        CamView();
    }
    else
    {
       camViewFlag = false;
       ui->pPBCamPlay->setText("camera start");
       QPixmap pix("camtest.png");
       ui->pLabelCamView->setPixmap(pix);
       ui->pPBSnapShot->setEnabled(false);

    }
}
void CamCapture::snapShot()
{
    imwrite(fname,frame);
}
