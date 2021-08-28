
#ifndef __IDETECTION_MODULE_H__
#define __IDETECTION_MODULE_H__

#include "Common.h"
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace smartmore
{
    //!
    //! \struct BoxInfo
    //!
    //! Struct to store all the info related to objects detected by this module.
    //!
    struct BoxInfo
    {
        int32_t label_id;       //!< The label id of this box.
        std::string label_name; //!< The label name of this box.

        float score; //!< The score of this box.
        float xmin;  //!< The minimal x coordinate of this box.
        float xmax;  //!< The maximal x coordinate of this box.
        float ymin;  //!< The minimal y coordinate of this box.
        float ymax;  //!< The maximal y coordinate of this box.
    };

    //!
    //! \struct DetectionRequest
    //!
    struct DetectionRequest
    {
        cv::Mat image;
        std::vector<float> thresholds; //!< The threshold is used to judge the classification.
    };

    //!
    //! \struct DetectionResponse
    //!
    struct DetectionResponse
    {
        cv::Mat mask; //!< The item list detected by this module.
		std::map<int, std::string> names;
        QCCode code;
    };

    //!
    //! \class IDetectionModule
    //!
    //! \brief Base DetectionModule class for user-implemented layers.
    //!
    class DLL_API IDetectionModule
    {
    public:
        IDetectionModule() = default;
        virtual ~IDetectionModule() = default;

        //!
        //! \brief Get version information of the model.
        //!
        //! \return The version information.
        //!
        //! Version information should include the MD5 of model and the build time of this SDK.
        //! (e.g. "Version: 1.0.0"
        //!       "Model MD5: 87d2c0a12551f0fc807b9a2aec207543"
        //!       "SDK CreateTime: Nov  5 2020 17:00:00")
        //!
        virtual std::string Version() = 0;

        //!
        //! \brief Init DetectionModule with given model path.
        //!
        //! \param input_model_path The path of input model.
        //! \param use_gpu Whethre use gpu in subsequent inference.
        //! \param device_id ID of gpu used.
        //!
        //! \return The status of Initialization. OK for success, else non-zero.
        //!
        //! In particular, this function is called prior to any call to Run().
        //!
        virtual ResultCode Init(const std::string &input_model_path,
                                const bool use_gpu,
                                const int device_id) = 0;

        virtual ResultCode Init(const std::string &input_model_path,
                                const bool use_gpu,
                                const int device_id,
                                const std::string &config_path) = 0;

        //!
        //! \brief Do inference.
        //!
        //! \param req Intput request.
        //! \param rsp Output response.
        //!
        //! \return The status of Run. OK for success, else non-zero.
        //!
        virtual ResultCode Run(const DetectionRequest &req, DetectionResponse &rsp) = 0;

		virtual ResultCode Visualize(const DetectionRequest &req,
			const DetectionResponse &rsp,
			cv::Mat &image, std::vector<double> &areas) = 0;

    };
} // namespace smartmore

#endif