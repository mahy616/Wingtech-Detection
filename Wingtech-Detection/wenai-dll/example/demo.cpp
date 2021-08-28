
#include "VimoDetectionModule.h"

int main()
{
	std::string model_path = "./../model/wentai_1st_emtpy.smartmore";
	std::string input_image = "./../_data/testimage/Image_20210726193633463.bmp";
	std::string output_image = "./../_data/vis/result_Image_20210726193633463.bmp";

    smartmore::VimoDetectionModule module;
   if (module.Init(model_path, false, 0) != smartmore::ResultCode::Success)
    {
        std::cout << "Init module failed!" << std::endl;
        return 1;
    }
	std::cout << module.Version() << std::endl;
    smartmore::DetectionRequest req;
	smartmore::DetectionResponse rsp;
	req.thresholds = { 0.8f };
    req.image = cv::imread(input_image);
    std::cout << "Init success" << std::endl;

    module.Run(req, rsp);
    std::cout << "Run success" << std::endl;

	// std::vector<double> areas;
	// cv::Mat image;
	// module.Visualize(req, rsp, image, areas);

	// std::cout <<"缺陷个数 ： "<< areas.size() << std::endl;
	// for (size_t i = 0; i < areas.size(); i++)
	// {
	// 	std::cout << "第 "<<i<<" 个缺陷面积为 "<<areas[i] << std::endl;
	// }
	
	// cv::imwrite(output_image, image);

	// std::string result = "NOT Available";
	// if (rsp.code == smartmore::QCCode::NG) {
	// 	result = "NG";
	// }
	// else if (rsp.code == smartmore::QCCode::OK) {
	// 	result = "OK";
	// }
	// std::cout << "result: " << result << std::endl;

 
}
