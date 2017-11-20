//
// Created by zouz on 20/11/17.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGEREXCEPTION_HPP
#define LIFEISBORNE_RESSOURCEMANAGEREXCEPTION_HPP

#include <bits/exception.h>
#include <string>



class LoadingError : public std::exception {
public:
   explicit LoadingError(const std::string &precision):
           _precision(precision)
   {

   }

    ~LoadingError() = default;

public:
    const std::string what() {
        std::string tmp("[LoadingError]:");
        tmp += _precision;
        tmp += "\n";
       return tmp;
    }
private:
    const std::string _precision;
};

#endif //LIFEISBORNE_RESSOURCEMANAGEREXCEPTION_HPP
