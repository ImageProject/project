//#include <cv.h>
//#include <highgui.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//IplImage* image = 0;
//IplImage* dst = 0;
//IplImage* dst2 = 0;
//
//int main(int argc, char* argv[])
//{
//        // ��� �������� ������� ������ ����������
//        char* filename = argc == 2 ? argv[1] : "Image0.jpg";
//        // �������� ��������
//        image = cvLoadImage(filename,1);
//        // ������ ��������
//        dst = cvCreateImage( cvSize(image->width+20, image->height+20), image->depth, image->nChannels);
//        dst2 = cvCreateImage( cvSize(image->width+20, image->height+20), image->depth, image->nChannels);
//
//        printf("[i] image: %s\n", filename);
//        assert( image != 0 );
//
//        // ���� ��� ����������� ��������
//        cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("IPL_BORDER_CONSTANT",CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("IPL_BORDER_REPLICATE",CV_WINDOW_AUTOSIZE);
//
//        // ��������� ��������
//        cvCopyMakeBorder(image, dst, cvPoint(10,10), IPL_BORDER_CONSTANT, cvScalar(250));
//        cvCopyMakeBorder(image, dst2, cvPoint(10,10), IPL_BORDER_REPLICATE, cvScalar(250));
//
//
//        // ���������� ��������
//        cvShowImage("original",image);
//        cvShowImage("IPL_BORDER_CONSTANT",dst);
//        cvShowImage("IPL_BORDER_REPLICATE",dst2);
//
//        // ��� ������� �������
//        cvWaitKey(0);
//
//        // ����������� �������
//        cvReleaseImage(&image);
//        cvReleaseImage(&dst);
//        cvReleaseImage(&dst2);
//        // ������� ����
//        cvDestroyAllWindows();
//        return 0;
//}