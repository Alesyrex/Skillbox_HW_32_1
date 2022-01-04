#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <map>
#include <fstream>

class Cinema
{
public:
    std::string title;
    std::string creation_date;
    std::string studio;
    std::string country;
    std::string director;
    std::string written;
    std::string producer;
    std::map<std::string,std::string> cast;
};

int main() {

    Cinema cinema;

    cinema.title = "Spider-man:No way home";
    cinema.country = "USA";
    cinema.studio = "Marvel";
    cinema.creation_date = "15/12/2021";
    cinema.director = "Jon Watts";
    cinema.producer = "Victoria Alonso";
    cinema.written = "Stan Lee";
    cinema.cast = {{"Tom Holland","Peter Parker"},
                   {"Zendaya","MJ"},
                   {"Willem Dafoe","Norman Osborn"},
                   {"Benedict Cumberbatch","Doctor Strange"}};

    nlohmann::json dict;
    std::ofstream data("Cinema.json");

    dict["title"] = cinema.title;
    dict["country"] = cinema.country;
    dict["studio"] = cinema.studio;
    dict["cast"] = cinema.cast;
    dict["creation_date"] = cinema.creation_date;
    dict["director"] = cinema.director;
    dict["written"] = cinema.written;
    dict["producer"] = cinema.producer;

    data << dict;
    return 0;
}
