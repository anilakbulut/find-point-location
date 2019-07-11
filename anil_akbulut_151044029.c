#include <stdio.h>
#define class_num 10
/* ANIL AKBULUT 151044029 HW1*/
int main(){
	double class1x,class1y,class2x,class2y,sumx=0.0,sumy=0.0,slope_avg,slope_perp,slope_test,slope_avg1,slope_avg2;
	int i=class_num,j=1,status; /* Variables*/
	double avgclass1x,avgclass1y,avgclass2x,avgclass2y;	/* x and y values of class 1 and class 2*/
	double midptx,midpty; /* midpoint of class 1 and class 2*/
	double test_p_x,test_p_y; /* x and y values of test point*/
	double minx,miny; /* minimum and maximum values of class1 and class2*/
	while(i>0)  /* class1 point and max,min values received */
	{
		scanf("%lf %lf",&class1x,&class1y);
		if(j==1)
		{
			minx=class1x;
			miny=class1y;
			j++;
		}
		if(minx>class1x)
		{
			minx=class1x;
		}
		if(miny>class1y)
		{
			miny=class1y;
		}
		sumx=sumx+class1x;
		sumy=sumy+class1y;
		i--;
	}
	avgclass1x=sumx/class_num;	/*x average of class 1*/
	avgclass1y=sumy/class_num;	/*y average of class 2*/
	sumx=0.0;
	sumy=0.0;
	i=class_num;
	while(i>0) 	/* class2 point and max,min values received */
	{
		scanf("%lf %lf",&class2x,&class2y);
		if(minx>class2x)
		{
			minx=class2x;
		}
		if(miny>class2y)
		{
			miny=class2y;
		}
		sumx=sumx+class2x;
		sumy=sumy+class2y;
		i--;
	}
	minx--; /* reduced values */
	miny--;
	avgclass2x=sumx/class_num;	/*average of class1*/
	avgclass2y=sumy/class_num; /*average of class2*/
	midptx=(avgclass1x+avgclass2x)/2;	/*x values of mid point*/
	midpty=(avgclass1y+avgclass2y)/2;	/*y values of mid point*/
	status = scanf("%lf %lf",&test_p_x,&test_p_y); 
	while(status > 0)	/* looped with status*/
	{
		if(avgclass1x==avgclass2x) /*horizontal separate situation */
		{
			if(test_p_y>midpty && avgclass1y>midpty)
			{
				printf("class 1\n");
			}
			else if(test_p_y<midpty && avgclass1y<midpty)
			{
				printf("class 1\n");
			}
			else printf("class 2\n");
		}
		else if(avgclass1y==avgclass2y) /*vertical separate line situation*/
		{
			if(test_p_x<midptx && avgclass1x<midptx)
			{
				printf("class 1\n");
			}
			else if(test_p_x>midptx && avgclass1x>midptx)
			{
				printf("class 1\n");
			}
			else printf("class 2\n");
		}
		else
		{
			slope_avg=(avgclass2y-avgclass1y)/(avgclass2x-avgclass1x);	 /* slope of average line*/
			slope_perp=(-1)/slope_avg;	/*slope of separate line*/
			slope_test=(test_p_y - miny)/(test_p_x - minx);/* use minx ,miny and test point for find slope of test point */
			slope_avg1=(avgclass1y-miny)/(avgclass1x-minx);/*use minx,miny and average of class1 and class2 for find slope avg1*/
			slope_avg2=(avgclass2y-miny)/(avgclass2x-minx);/*use minx,miny and average of class1 and class2 for find slope avg2*/
			if(slope_test>slope_perp && slope_avg1>slope_perp)
			{
				printf("class 1\n");
			}
			else if(slope_test>slope_perp && slope_avg1<slope_perp)
			{
				printf("class 2\n");
			}
			else if(slope_test<slope_perp && slope_avg2<slope_perp)
			{
				printf("class 2\n");
			}
			else if(slope_test<slope_perp && slope_avg2>slope_perp)
			{
				printf("class 1\n");
			}
		}
		status = scanf("%lf %lf",&test_p_x,&test_p_y);
	}
}
