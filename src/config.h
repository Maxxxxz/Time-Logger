#ifndef CONF
#define CONF

#include <string>

typedef struct Conf
{
    std::string LANG = "MISSING";
    int default_open_frame = 0;

    // Positons
    int top_level_window_pos_x = 50;
    int top_level_window_pos_y = 100;
    int top_level_window_length = 500;
    int top_level_window_height = 250;

    // Sizes


    // About
    std::string about_name = "MISSING";
    std::string about_software = "MISSING";
    std::string about_title = "MISSING";
    std::string about_version = "MISSING";
    std::string about_website = "MISSING";
    std::string about_text = "MISSING";

    // Menu Bar Text
    std::string menu_file = "MISSING";
    std::string menu_help = "MISSING";
    std::string menu_quit = "MISSING";

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