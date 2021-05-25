#include <iostream>
#include <cassert>
#include <cstring>
#include <exception>
/*
class MyException : public std::exception {
public:
    virtual const char* what() const noexcept;
};
*/
class MyExceptionInsert : public std::exception {
private:
    unsigned int _pos;
    unsigned int _size;
public:
    const char* what() const noexcept;
    MyExceptionInsert(unsigned int p, unsigned int s);
};

class MyExceptionAt : public std::exception {
private:
    unsigned int _pos;
    unsigned int _size;
public:
    const char* what() const noexcept;
    MyExceptionAt(unsigned int p, unsigned int s);
};

class MyExceptionErase : public std::exception {
private:
    unsigned int _pos;
    unsigned int _size;
public:
    const char* what() const noexcept;
    MyExceptionErase(unsigned int p, unsigned int s);
};

class MyString
{
public:
    /// c-tor
    MyString(const char* rawString = nullptr);

    /// the rule of five
    explicit MyString(const MyString& other); //предотвращает неявное преобразование типов при инициализации MyString
    MyString(MyString&& other) noexcept; //нельзя перегружать

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    ~MyString();
    ///
    
    /// Modifiers
    /*!
        appends string to source добавляет строку к источнику
        \param appendedString - string that is inserted at the end строка, которая вставляется в конце
    */
    void append(const MyString& appendedString);//типа строка + строка

    /*!
        inserts string at the passed position <br>
        \param pos - insertion index
        \param insertedString - string that is inserted at the pos
    */
    void insert(unsigned int pos, const MyString& insertedString);

    /*!
        clear string
    */
    void clear();

    /*!
        removes count characters from the string starting from pos index. <br>
        if count > size - pos then count := size - pos
        \param pos - erasing index
        \param count - count of characters to remove
    */
    void erase(unsigned int pos, unsigned int count); //стирает нужне колво символов начиная с чего-то там
    ///

    /// Accessors //
    /*!
        access to character at the idx
        \param idx - character index
        \return reference to character
    */
    char& at(unsigned int idx); //возвращает букавку  с номером
    const char& at(unsigned int idx) const; 

    /*!
        get string sise
        \return count of characters
    */
    unsigned int size() const; 

    /*!
        check that string is empty
        \return true if string is empty else false
    */
    bool isEmpty() const;//пустая ли

    /*!
        get non-modified raw string 
        \return c-style string
    */
    const char* rawString() const;
    ///

    /// Search
    unsigned int find(const MyString& substring, unsigned int pos = 0);
    ///

    /// Compares
    /*!
        analogue of strcmp
    */
    int compare(const MyString& comparableString) const;
    ///

    /// Overloads //переопределение
    /*!
        see at-methods
    */
    char& operator[](unsigned int idx);
    const char& operator[](unsigned int idx) const; 

    /*!
        see append-method
    */
    MyString& operator+(const MyString& appendedString);

    /*!
        see compares section
    */
    bool operator==(const MyString& comparableString) const;
    bool operator!=(const MyString& comparableString) const;
    bool operator>(const MyString& comparableString) const;
    bool operator<(const MyString& comparableString) const;
    bool operator>=(const MyString& comparableString) const;
    bool operator<=(const MyString& comparableString) const;

    void printf();
private:
    char* _data;
    unsigned int _size;
};