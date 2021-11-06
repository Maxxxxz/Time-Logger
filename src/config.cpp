#include "config.h"
#include <iostream>

#include <yaml-cpp/yaml.h>

void Config::loadSettings(const std::string& settings_filename)
{
    try
    {
        // settings_filename will only contain settings, including selected language.
        // Based on the selected language, we will search the languages folder 
        YAML::Node settings = YAML::LoadFile(settings_filename);
        
        this->cfg.LANG = settings["language"].as<std::string>();

        auto lang_filename = "./lang/" + this->cfg.LANG + ".yaml";

        YAML::Node config = YAML::LoadFile(lang_filename);

        // About
        this->cfg.about_name = config["about"]["name"].as<std::string>();
        this->cfg.about_software = config["about"]["software"].as<std::string>();
        this->cfg.about_title = config["about"]["title"].as<std::string>();
        this->cfg.about_version = config["about"]["version"].as<std::string>();
        this->cfg.about_website = config["about"]["website"].as<std::string>();

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