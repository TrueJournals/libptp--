#ifndef LIBPTP_PP_CHDKCAMERA_H_
#define LIBPTP_PP_CHDKCAMERA_H_

#include <string>
#include <vector>
#include "CameraBase.hpp"

namespace PTP {
    
    class PTPContainer;
    class LVData;

    class CHDKCamera : public CameraBase {
        static uint8_t * _pack_file_for_upload(uint32_t * out_size, std::string local_filename, std::string remote_filename);
        public:
            CHDKCamera();
            CHDKCamera(libusb_device *dev);
            float get_chdk_version(void);
            uint32_t check_script_status(void);
            uint32_t execute_lua(std::string script, uint32_t * script_error, bool block=false);
            void read_script_message(PTPContainer * out_data, PTPContainer * out_resp);
            uint32_t write_script_message(std::string message, uint32_t script_id=0);
            bool upload_file(std::string local_filename, std::string remote_filename, int timeout=0);
            char * download_file(std::string filename, int timeout);
            void get_live_view_data(LVData * data_out, bool liveview=true, bool overlay=false, bool palette=false);
            std::vector<std::string> _wait_for_script_return(int timeout);
    };
    
}

#endif /* LIBPTP_PP_CHDKCAMERA_H_ */