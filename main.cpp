#include "mainwindow.h"

#include <QApplication>
#include <exprtk.hpp>
#include <QVector>
#include "initer.h"
#include "expTest.cpp"

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],"--start") == 0){
            //qDebug()<<"console mode";
            Initer::GeneralInit();
        }
    }
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    return a.exec();
}
