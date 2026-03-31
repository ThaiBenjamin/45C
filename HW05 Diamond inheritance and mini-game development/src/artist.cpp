// artist.cpp: function definitions file for artist.h

// place header file includes here
#include "../include/artistList.hpp"
#include <string>
#include <iostream>
// Allocate a new artist record
Artist::Artist(const std::string & artist_id, const std::string & artist_name, int total_followers, std::string genres[Artist::max_genres], int popularity) {
  this->artist_id = artist_id;
  this->artist_name = artist_name;
  this->total_followers = total_followers;
  for(int i = 0; i < static_cast<int>(Artist::max_genres); ++i){
    this->genres[i] = genres[i];
  }
    
  this->popularity = popularity;
}

// Print an artist record
void Artist::printArtist() const{
  std::cout << "Artist ID: " << artist_id << "\n";
  std::cout << "Artist Name: " << artist_name << "\n";
  std::cout << "Total Followers: " << total_followers << "\n";
  std::cout << "Genres: ";
  for(int i = 0; i < static_cast<int>(Artist::max_genres); ++i){
    if(genres[i].empty()){
      continue;
    }
    else{
      std::cout << genres[i] << ", ";
    }
  }
  std::cout << "\nPopularity: " << popularity;
}

const std::string& Artist::name() const {
  return artist_name;
}
const std::string& Artist::id() const {
  return artist_id;
}