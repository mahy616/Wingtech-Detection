/*
 * @Descripttion: 
 * @version: 
 * @Author: max.ma
 * @Date: 2020-11-23 15:50:24
 * @LastEditors: max.ma
 * @LastEditTime: 2020-11-23 22:15:19
 */
#ifndef __VIMO_OCR_MODULE_H__
#define __VIMO_OCR_MODULE_H__

#include <memory>
#include <string>
#include <opencv2/opencv.hpp>
#include "Common.h"
#include "IOCRModule.h"

namespace smartmore
{
    class DLL_API VimoOCRModule : public IOCRModule
    {
    public:
        VimoOCRModule();
        ~VimoOCRModule();

        /**
            sdk版本号
            @return sdk版本号字符串
        */
        std::string Version() override;
        /**
            sdk初始化
            @param  input_model_path ：模型路径
            @param  USE_GPU             ：是否使用gpu
            @param  device_id         ：设备id
            @return 返回码 ：0：成功； 其他值：失败
        */
        ResultCode Init(
            const std::string &input_model_path,
            const bool use_gpu,
            const int device_id) override;

        /**
            sdk处理
            @param  req ：sdk输入参数结构体的引用
            @param  rsp    ：sdk输出结果结构体的引用
            @return 返回码 ：0：成功； 其他值：失败
        */
        ResultCode Run(const OCRRequest &req, OCRResponse &rsp) override;

    private:
        class Impl;
        std::shared_ptr<Impl> impl_;
    };

} // namespace smartmore

#endif
