// artistList.cpp: function definitions for prototypes for artistList.h header file
// place header includes here
#include "../include/parse_csv.hpp"

ArtistList::ArtistEntry::ArtistEntry(ArtistList* list, const Artist& a) {
  /* Insert your code here */
  this->list = list;
  this->next = nullptr; 
  this->prev = nullptr;
  this->artist = a;

}

// Allocate a new artist list
ArtistList::ArtistList() {
  /* Insert your code here */ 
  length = 0;
  first = nullptr;
  last = nullptr;
}

std::size_t ArtistList::size() const {
  /* Insert your code here */
  return length;
}

bool ArtistList::is_empty() const {
  /* Insert your code here */
  return length == 0;
}

ArtistList::ArtistList(const ArtistList & list) {
  /* Insert your code here */
  first = nullptr;
  last = nullptr;
  length = 0;

  ArtistEntry *currNode = list.first;

  while(currNode != nullptr){
    appendArtist(currNode->artist);
    currNode = currNode->next;
  }
  
}

// Delete a artist list (and all entries)
ArtistList::~ArtistList() noexcept {
  /* Insert your code here */
  ArtistEntry *currNode = first;

  while(currNode != nullptr){
    ArtistEntry *nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }

  first = nullptr;
  last = nullptr;
  length = 0;
}

// prepend an artist at the beginning of list
void ArtistList::prependArtist(const Artist& a) {
  /* Insert your code here */
  ArtistEntry *entry = new ArtistEntry(this, a);
  if(first == nullptr && last == nullptr){
    first = last = entry;
  }
    
  else{
    entry->next = first;
    first->prev = entry;
    first = entry;
  }
  length += 1;
}

// append an artist to the end of the list *Good*
void ArtistList::appendArtist(const Artist& a) {
  /* Insert your code here */
  ArtistEntry *entry = new ArtistEntry(this, a);
  if(first == nullptr && last == nullptr){
    first = last = entry;
  }
    
  else{
    entry->prev = last;
    last->next = entry;
    last = entry;
  }
  length += 1;
}

// remove the first artist from the list *Good*
void ArtistList::removeFirstArtist() {
  /* Insert your code here */
  

  if(first == nullptr){
      return;
  }
  
  ArtistEntry *tempNode = first;
  first = first->next;

  if(first != nullptr){
    first->prev = nullptr;
  }
  else{
    last = nullptr;
  }
  delete tempNode;
  length -=1;
}

// remove last artist from the list *Good*
void ArtistList::removeLastArtist() {
  /* Insert your code here */
  if(last == nullptr){
    return;
  }
  
  ArtistEntry *tempNode = last;
  last = tempNode->prev;
  if(last != nullptr){
    last->next = nullptr;
  }
  else{
    first = nullptr;
  }
  delete tempNode;
  length-=1;
}

// print an artist list 
void ArtistList::printArtistList() const {
  /* Insert your code here */
  
  if(first == nullptr){
    return;
  }
  ArtistEntry *currNode = first;

  while(currNode != nullptr){
    currNode->artist.printArtist();
    currNode = currNode->next;
  }
  
}

// find an artist by name in an unsorted list 
Artist *ArtistList::findArtistName(const std::string& name) const {
  /* Insert your code here */
  ArtistEntry *currNode = first;
  
  while(currNode != nullptr){
      if(currNode->artist.name() == name){
        return &(currNode->artist);
    }
    currNode = currNode->next;
  }
  
  return nullptr;
}

// remove artist by name in an unsorted list
void ArtistList::removeArtistbyName(const std::string & name) {
  /* Insert your code here */
  ArtistEntry *currNode = first;

  while(currNode != nullptr && currNode->artist.name() != name){
    currNode = currNode->next;
  }

  if(currNode == nullptr){
    return;
  }

  if(currNode == first){
    first = currNode->next;
    if(first != nullptr){
      first->prev = nullptr;
    }
    else{
      last = nullptr;
    }
  }
  else if(currNode == last){
    last = currNode->prev;
    last->next = nullptr;
  }
  else{
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
  }

  delete currNode;
  length -= 1;
}

void ArtistList::insertArtistAt(std::size_t index, const Artist& artist) {
  /* Insert your code here */
  if(index == 0){
    prependArtist(artist);
    return;
  }

  if(index == length){
    appendArtist(artist);
    return;
  }

  if(index > length){
    return;
  }
  
  ArtistEntry* newEntry = new ArtistEntry(this, artist);
  ArtistEntry *currNode = first;

  for(int i = 0; i < static_cast<int>(index); i++){
    currNode = currNode->next;
  }

  newEntry->next = currNode;
  newEntry->prev = currNode->prev;
  currNode->prev->next = newEntry;
  currNode->prev = newEntry;
  length+=1;
}

Artist * ArtistList::at(size_t index) {
  /* Insert your code here */
  ArtistEntry *currNode = first;

  for(int i = 0; i < static_cast<int>(index); i++){
    currNode = currNode->next;
  }

  return &(currNode->artist);

}

const Artist * ArtistList::at(size_t index) const {
  /* Insert your code here */
  ArtistEntry *currNode = first;

  for(int i = 0; i < static_cast<int>(index); i++){
    currNode = currNode->next;
  }

  return &(currNode->artist);
}

Artist* ArtistList::firstArtist() {
  /* Insert your code here */
  if(first != nullptr){
    return &(first->artist);
  }

  return nullptr;
}

const Artist* ArtistList::  firstArtist() const {
  /* Insert your code here */
  if(first != nullptr){
    return &(first->artist);
  }

  return nullptr;
}

Artist* ArtistList:: lastArtist() {
  /* Insert your code here */
  if(last != nullptr){
    return &(last->artist);
  }

  return nullptr;
}

const Artist* ArtistList:: lastArtist() const {
  /* Insert your code here */
  if(last != nullptr){
    return &(last->artist);
  }

  return nullptr;
}


