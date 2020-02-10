#pragma once
#include <opencv2/opencv.hpp>
class Hough_space
{
public:
	Hough_space(cv::Mat edge_img);

	//-------- methods -----------
	void save_to_csv(std::string filename);
	// ------ Not settled on yet --------
	void get_shifted_hough(); // check whether important clusters exist at top and bottom, if so, perform shifting



private:
	cv::Mat edge_img;
	cv::Mat hough_space;
	int img_height;
	int img_width;
	int hough_height;
	int hough_width;
	int resolution_rho;
	int rho_max;
	float resolution_theta;
	int num_angle;
	std::vector<float> theta_tick;
	std::vector<int> rho_tick;
	std::vector<std::vector<double>> lines;

	//-------------- Methods ---------------------
	cv::Point get_parameters(cv::Point idx_point);
	void initialise_hough_space();
	void fill_ticks();
	void find_lines(int accum_threshold);



};

