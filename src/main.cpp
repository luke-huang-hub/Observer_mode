
#include "observer.h"
#include "subject.h"

#include <QtCore/QVariant>
#include <QtCore/QtDebug>
#include <QtWidgets/QApplication>
#include <iostream>
#include <stdio.h>
using namespace robosense::lidar;
//https://blog.csdn.net/zd_shu/article/details/108525056
//当两个对象的观察者重合，如何在复杂项目中添加观察者，auto的使用
int main(int argc, char* argv[])
{
  SubjectBase* subjectone = new Subject();
  ObserveBase* observeone = new Observe(subjectone);
  subjectone->addObserve(observeone);
  subjectone->notify();
  subjectone->deleteObserve(observeone);

  delete subjectone;
  delete observeone;
  return 0;
}
