#ifndef CONF
#define CONF

#include <string>

typedef struct Conf
{
    std::string LANG = "MISSING";
    // About
    std::string about_name = "MISSING";
    std::string about_software = "MISSING";
    std::string about_title = "MISSING";
    std::string about_version = "MISSING";
    std::string about_website = "MISSING";

    // Menu Bar Text
    std::string menu_file = "MISSING";
    std::string menu_help = "MISSING";

    // Calendar Log
    std::string calendar_title = "MISSING";
} Conf;

class Config
{
    public:
        static Config& getInstance()
        {
            static Config instance;
            return instance;
        }

        Conf getConf();

        void loadSettings(const std::string& settings_filename);

        Config(Config const&) = delete;
        void operator=(Config const&) = delete;
    private:
        Config(){};
        std::string filename;
        Conf cfg;
};

#endif