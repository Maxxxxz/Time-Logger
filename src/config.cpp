#include "config.h"
#include <iostream>

#include <yaml-cpp/yaml.h>

void Config::loadSettings(const std::string& settings_filename)
{
    try
    {
        // settings_filename will only contain settings, including selected language.
        // Based on the selected language, we will search the languages folder 

        {
            YAML::Node settings = YAML::LoadFile(settings_filename);
            
            this->cfg.LANG = settings["language"].as<std::string>();
            this->cfg.default_open_frame = settings["default-open-frame"].as<int>();
            this->cfg.top_level_window_pos_x = settings["positions"]["top-level-window-pos-x"].as<int>();
            this->cfg.top_level_window_pos_y = settings["positions"]["top-level-window-pos-y"].as<int>();
            this->cfg.top_level_window_length = settings["sizes"]["top-level-window-length"].as<int>();
            this->cfg.top_level_window_height = settings["sizes"]["top-level-window-height"].as<int>();

        }

        auto lang_filename = "./lang/" + this->cfg.LANG + ".yaml";

        YAML::Node config = YAML::LoadFile(lang_filename);

        // About
        this->cfg.about_name = config["about"]["name"].as<std::string>();
        this->cfg.about_software = config["about"]["software"].as<std::string>();
        this->cfg.about_title = config["about"]["title"].as<std::string>();
        this->cfg.about_version = config["about"]["version"].as<std::string>();
        this->cfg.about_website = config["about"]["website"].as<std::string>();
        this->cfg.about_text = config["about"]["text"].as<std::string>();

        // Menu Bar
        this->cfg.menu_file = config["menu-text"]["file"].as<std::string>();
        this->cfg.menu_help = config["menu-text"]["help"].as<std::string>();

        // Calendar Log
        this->cfg.calendar_title = config["calendar-log"]["title"].as<std::string>();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Conf Config::getConf()
{
    return this->cfg;
}