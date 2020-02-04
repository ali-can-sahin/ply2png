#include <iostream>
#include <string>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/passthrough.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char *argv[])
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcl_points;
	pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
	
	pcl_points = pcl::PointCloud<pcl::PointXYZRGB>::Ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
	pcl::io::loadPLYFile(argv[1],*pcl_points);
	viewer.removeAllPointClouds();
	viewer.addPointCloud(pcl_points,"ply");
	viewer.setShowFPS(false);


	viewer.setSize(400,1024);
	for(int i=0;i<10000000;i++)
		viewer.spinOnce();
	viewer.saveScreenshot(argv[2]);
	viewer.spinOnce();

}


