// must complete parse_csv function for code to work properly with .csv files
#include <artistList.hpp>
#include <istream>
#include <iostream>
#include <sstream>


// helper function provided to parse genres WITH square brackets
static void parse_genres(std::istream & file, std::string genres[Artist::max_genres]) {
    std::string temp;

    std::getline(file, temp, '[');
    std::getline(file, temp, ']');

    auto genre_idx = 0u;
    for(auto start = 0u; start < temp.size() and genre_idx < Artist::max_genres; ){
        auto start_quote = temp.find_first_of('\'', start) + 1;
        auto end_quote = temp.find_first_of('\'', start_quote);
        
        genres[genre_idx] = temp.substr(start_quote, end_quote - start_quote);
        ++genre_idx;

        start = end_quote + 1;
    }
    
    while(genre_idx < Artist::max_genres){
        genres[genre_idx] = "";
        ++genre_idx;
    }
}

// parse_csv needs to be written by the students
ArtistList parse_csv(std::istream& file) {
    // Insert code here
   // be sure to call the provided parse_genres function to assist you
   // in reading the genres column from the spotify_daily_charts_artists.csv
    ArtistList artist_list;
    std::string line;

    std::getline(file, line);

    while(std::getline(file,line)){
        std::stringstream ss(line);

        std::string artist_id;
        std::string artist_name;
        std::string followers_str;
        std::string popularity_str;
        std::string junk;
        std::string genres_array[Artist::max_genres];

        std::getline(ss, artist_id, ',');
        std::getline(ss, artist_name, ',');
        std::getline(ss, followers_str, ',');
        parse_genres(ss, genres_array);
        std::getline(ss, junk, ',');
        std::getline(ss, popularity_str);

        Artist artist(artist_id, artist_name, std::stoi(followers_str), genres_array, std::stoi(popularity_str));
        artist_list.appendArtist(artist);

    }
    return artist_list;
}
   