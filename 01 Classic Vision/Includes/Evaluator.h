#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include "util.h"
#include "data_loader.h"
#include "Detector.h"
#include "Brick_Detector.h"
#include "Chamfer_brick_detector.h"
class Evaluator
{
public:
	Evaluator();
	Evaluator(std::string path);
	Evaluator(std::string path_to_folder, std::string img_list_csv);
	void set_detector(Detector * detector_addr);
	void set_path(std::string path);
	bool evaluate_next_img(double threshold = 0.5);
	void open_file();
	void close_file();
	cv::Mat img_to_print;

private:
	double calculate_IoU(cv::Rect rect1, cv::Rect rect2);
	//void print_results_to_csv();
	void evaluate(double threshold);
	void save_evaluation(int true_pos, int false_pos, int false_neg);
	//std::string folder_path;
	Data_loader loader;
	std::ofstream file;
	Detector * detector;
    std::vector<cv::Rect> false_positive;
    std::vector<cv::Rect> true_positive;
};

