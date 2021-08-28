
#ifndef __SM_DETECTION_MODULE_H__
#define __SM_DETECTION_MODULE_H__

#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <thread>
#include <opencv2/opencv.hpp>
#include "IDetectionModule.h"


enum  Severity
{
    kError,
    kWarming,
    kInfo,
    kVerbose,
};

#ifdef DEBUG_LOG
void Log(Severity severity, const std::string msg)
{
    std::ofstream fout("./outtxt.txt", std::ios::app);
    std::thread::id this_id = std::this_thread::get_id();
    switch (severity)
    {
    case kInfo:
        fout << "[Vimo] [I] [Thread(" << this_id << ")]" << msg << std::endl;
        break;
    case kError:
        fout << "[Vimo] [E] [Thread(" << this_id << ")]" << msg << std::endl;
        break;
    case kWarming:
        fout << "[Vimo] [W] [Thread(" << this_id << ")]" << msg << std::endl;
        break;
    case kVerbose:
        fout << "[Vimo] [V] [Thread(" << this_id << ")]" << msg << std::endl;
        break;
    default:
        break;
    }
    fout << std::flush;
    fout.close();
}
#else
#endif

namespace smartmore
{
    class DLL_API VimoDetectionModule : public IDetectionModule
    {
    public:
        VimoDetectionModule();
        ~VimoDetectionModule();

        std::string Version() override;

        ResultCode Init(const std::string &input_model_path,
                        const bool use_gpu,
                        const int device_id) override;
        
        ResultCode Init(const std::string &input_model_path,
                        const bool use_gpu,
                        const int device_id,
                        const std::string &config_path) override;

        ResultCode Run(const DetectionRequest &req, DetectionResponse &rsp) override;

		ResultCode Visualize(const DetectionRequest &req,
			const DetectionResponse &rsp,
			cv::Mat &image, std::vector<double> &areas) override;

    private:
        class Impl;
        std::shared_ptr<Impl> _impl;
    };
} // namespace smartmore

#endif