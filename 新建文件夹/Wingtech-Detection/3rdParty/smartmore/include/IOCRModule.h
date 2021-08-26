/******************************************************************************
* FILENAME:      IOCRModule.h
* 
* AUTHORS:       Zhou Chao
* 
* START DATE:    Tuesday, 10th November 2020
* 
* CONTACT:       chao.zhou@smartmore.com
******************************************************************************/

#ifndef __IOCR_MODULE_H__
#define __IOCR_MODULE_H__

#include "Common.h"
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

namespace smartmore
{
    struct Point
    {
        float x, y;
        Point() = default;
        Point(float x_, float y_) : x(x_), y(y_) {}
    };

    struct Region
    {
        std::array<Point, 4> points;
    };
    //!
    //! \struct OCRRequest
    //!
    struct OCRRequest
    {
        cv::Mat image;
        float threshold;
    };

    //!
    //! \struct Coordinate
    //!
    struct Coordinate
    {
        float x, y;
    };

    //!
    //! \struct TextBlock
    //!
    struct TextBlock
    {
        std::vector<Coordinate> polygon;
        std::string text;
        float confidence;
    };

    //!
    //! \struct OCRResponse
    //!
    struct OCRResponse
    {
        std::vector<TextBlock> blocks;
        QCCode code;
    };

    //!
    //! \class IOCRModule
    //!
    //! \brief Base OCRModule class for user-implemented layers.
    //!
    class DLL_API IOCRModule
    {
    public:
        IOCRModule() = default;
        virtual ~IOCRModule() = default;

    public:
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
        //! \brief Init OCRModule with given model path.
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

        //!
        //! \brief Do inference.
        //!
        //! \param req The origin request.
        //! \param rsp The respnse generates from Run.
        //!
        //! \return The status of Visualization. OK for success, else non-zero.
        //!
        virtual ResultCode Run(const OCRRequest &req, OCRResponse &rsp) = 0;

        //!
        //! \brief Visualize result.
        //!
        //! \param req The origin request.
        //! \param rsp The respnse generates from Run.
        //! \param image Output image.
        //!
        //! \return The status of Visualization. OK for success, else non-zero.
        //!
        virtual ResultCode Visualize(const OCRRequest &req,
                                     const OCRResponse &rsp,
                                     cv::Mat &image);
    };

} // namespace smartmore

#endif
