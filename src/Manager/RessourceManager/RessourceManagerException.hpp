//
// Created by zouz on 20/11/17.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGEREXCEPTION_HPP
#define LIFEISBORNE_RESSOURCEMANAGEREXCEPTION_HPP

#include <exception>
#include <string>


class UnknowedRessourceType : public std::exception {

public:
    UnknowedRessourceType(const std::string &RessourceName):
    _rName(RessourceName){}

    ~UnknowedRessourceType() = default;

public:

    const std::string what() {
        std::string tmp("[Error]:[Loading]:Unknow Ressource Type :");
        tmp += _rName.c_str();
        tmp += "\n";
        return tmp;
    }

private:
    const std::string _rName;
};

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
