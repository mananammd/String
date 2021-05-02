#include "MyString.h"


MyString::MyString(const char* rawString) {
    _size = strlen(rawString);
    _data = new char[_size + 1];
    strcpy(_data, rawString);
    _data[_size+1]='\0';
}

MyString::MyString(const MyString& other) {
    _size = other._size;
    _data = new char[_size + 1];
    strcpy(_data,other._data);
    _data[_size+1]='\0';
}

MyString::MyString(MyString&& other) noexcept{
    _size = other._size;
    _data = other._data;
    other._size = 0;
    other._data = nullptr;
}

MyString& MyString::operator=(const MyString& other) {
    _size = other._size;
    delete[] _data;
    _data = new char[_size];
    memcpy(_data, other._data,_size);
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    _size = other._size;
    delete[] _data;
    _data = other._data;
    other._size = 0;
    other._data = nullptr;
    return *this;
}

MyString::~MyString() {
    delete [] _data;
}

void MyString::append(const MyString& appendedString) {
    insert(_size, appendedString);
}

void MyString::insert(unsigned int pos, const MyString& insertedString) {
    char* buff = new char[_size + insertedString._size];
    memcpy(buff, _data, pos);
    memcpy(buff + pos,insertedString._data, insertedString._size);
    memcpy(buff + pos + insertedString._size, _data + pos, _size - pos);
    delete[] _data;
    _data = buff;
    _size = _size + insertedString._size;
}

void MyString::clear() {
    _data = nullptr;
    _size = 0;
}

void MyString::erase(unsigned int pos, unsigned int count) {
    if (count > _size - pos) {
        count = _size - pos;
    }
    for (int i = 0; i < _size - count; ++i) {
        if (i >= pos) {
            _data[i] = _data[i + count];
        }
    }
    _size -= count;

}

char& MyString::at(const unsigned int idx) {
    assert(idx < size());
    return _data[idx];
}

const char& MyString::at(const unsigned int idx) const {
    assert(idx < size());
    return _data[idx];
}

unsigned int MyString::size() const{
    int sizeLen = 0;
  /*  while (_data != "\0"){
        sizeLen++;
    }
    */
    return sizeLen;
}

bool MyString::isEmpty() const {
    return (_data == nullptr);
}

const char* MyString::rawString() const {
    char* newdata = new char[_size + 1];
    strcpy(newdata, _data); //memcpy
    newdata[_size]='\0';
    return newdata;
}

unsigned int MyString::find(const MyString& substring, unsigned int pos) {
    int j = 0;
    int needPos = -1;
    for (int i = pos; i < _size; ++i) {
        if (_data[i] == substring[j]) {
            j++;
            if (j == substring._size) {
                needPos = i - j;
                break;
            }
        }
        else {
            j = 0;
        }
    }
    if (needPos == -1){
        std::cout << "not find" << "\n";
    }
    else {
        return needPos;
    }
    return needPos;
}


int MyString::compare(const MyString& comparableString) const {
    int minSize = std::min(_size, comparableString._size);
    for (size_t i = 0; i < minSize; i++) {
        if(_data[i] != comparableString._data[i]) {
            return _data[i] - comparableString._data[i];
        }
    }
    return _size - comparableString._size;
}

char& MyString::operator[](unsigned int idx) {
    return at(idx);
}

const char& MyString::operator[](unsigned int idx) const {
    return at(idx);
}

MyString& MyString::operator+(const MyString& appendedString) {
    this->append(appendedString);
    return *this;
}

bool MyString::operator==(const MyString& comparableString) const {
    if (strcmp(comparableString._data, _data) == 0) {
        return true;
    }
    return false;
}

bool MyString::operator!=(const MyString& comparableString) const {
    return !operator==(*this);
}

bool MyString::operator>(const MyString& comparableString) const {
    if (_size > comparableString._size) {
        return 1;
    }
    else {
        return 0;
    }
}

bool MyString::operator<(const MyString& comparableString) const {
    return !operator>(comparableString);
}

bool MyString::operator>=(const MyString& comparableString) const {
    return (operator==(comparableString) || operator>(comparableString));
}

bool MyString::operator<=(const MyString& comparableString) const {
    return (operator==(comparableString) || operator<(comparableString));
}

void MyString::printf(){
    if(_size == 0)
        std::cout << "(nullptr)";
    for (int i = 0; i < _size; i++){
        std::cout << _data[i];
    }
    std::cout << "\n";
}
