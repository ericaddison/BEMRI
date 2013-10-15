
#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);
	//setGeometry(400, 250, 542, 390);

// define theta
	double dth = PI / (Ntheta);
	for(int i=0; i<Ntheta; i++)
		theta[i] = i*dth;

// set up regexp validator so numerical inputs can only be numbers
	QRegExp regExp1("[1-9][0-9.]{0,3}");
	mass1Edit->setValidator(new QRegExpValidator(regExp1, this));
	mass2Edit->setValidator(new QRegExpValidator(regExp1, this));
	smaEdit->setValidator(new QRegExpValidator(regExp1, this));

// set up more restrictive input for eccentricity
	QRegExp regExp2("[0][.][0-9 ]{0,3}");
	eccEdit->setValidator(new QRegExpValidator(regExp2, this));
	eccEdit->setInputMask("\\0\\.999");	// input mask for eccEdit to force input of the from 0.xxx, where the //0//. means 0 and . cannot be deleted

// connections
	connect(eccEdit,SIGNAL(returnPressed()),this,SLOT(replotOrbit()));

// get initial binary values
	getParams();
	plotOrbit();
}


// getParams: collect required binary parameters from lineEdits
void MainWindow::getParams()
{
	m1 = (mass1Edit->text()).toDouble();
	m2 = (mass2Edit->text()).toDouble();
	a =  (smaEdit->text()).toDouble();
	e =  (eccEdit->text()).toDouble();
}

void MainWindow::replotOrbit()
{
	getParams();
	plotOrbit();
}

void MainWindow::plotOrbit()
{
	QVector<double> x1(Ntheta,0), y1(Ntheta,0);
	QVector<double> x2(Ntheta,0), y2(Ntheta,0);
	double num = a*(1.0-e*e);
	double apo = a*(1+e);

	for(int i=0; i<Ntheta; i++)
	{
		x1[i] = num / (1.0 + e*cos(theta[i])) * cos(theta[i]);
		y1[i] = num / (1.0 + e*cos(theta[i])) * sin(theta[i]);
		x2[Ntheta-i-1] = x1[i];
		y2[Ntheta-i-1] = -y1[i];
	}


  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(x1, y1);
  customPlot->addGraph();
  customPlot->graph(1)->setData(x2, y2);
  // give the axes some labels:
  customPlot->xAxis->setLabel("x");
  customPlot->yAxis->setLabel("y");

  // set axes ranges, so we see all data:
  // determine width of graph so we can manually implement a square viewing perspective
  customPlot->replot();
  customPlot->rescaleAxes();
  int w = (customPlot->axisRect())->width();
  int h = (customPlot->axisRect())->height();
  double rat = fabs((double)w/(double)h);
//qDebug("w = %d, h = %d, rat = %.5f",w,h,rat);
  customPlot->xAxis->setRange(-apo*rat,apo*rat);
  customPlot->yAxis->setRange(-apo,apo);
  customPlot->replot();
}	
