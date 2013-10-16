
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "ui_mainWindow.h"
#include "qcustomplot.h" // the header file of QCustomPlot.
#include "../binary.h"	// header file for binary
#include "../ptMass.h"
#define PI 3.1415926
#define MAX(x,y) ((x)>(y)?(x):(y))

using namespace Astro;

class MainWindow;

class MainWindow : public QMainWindow, Ui::MainWindow
{

  Q_OBJECT

	public:
		MainWindow(QWidget *parent=0);

	private slots:
		void getParams();
		void plotTwoBodyOrbits();
		void replotTwoBodyOrbits();

	private:
		binary *bin;
		static const int Ntheta=500;
		double theta[Ntheta];
		

};

#endif
