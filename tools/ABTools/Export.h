//
// Created by desuex on 26.05.2020.
//

#ifndef ABWORLD_EXPORT_H
#define ABWORLD_EXPORT_H

#include <string>
#include<iostream>
#include<fstream>
#include <QString>

class Export {
private:
    std::ofstream file;
    int tabs = 0;
    void putTabs();

public:
    void openFileToSave(const QString &filename);
    void writeLine(const QString& key, const QString& value);
    void writeLine(const QString& key, int value);
    void writeLine(const QString& key, const std::uint16_t& value);
    void writeLine(const QString& key, const std::uint32_t& value);
    void writeLine(const QString &key, float value);
    void writeLine(const QString &key, bool value);
    void writeLineHex(const QString& key, const std::uint32_t& value);
    void openObject(const QString& name);
    void openObject(int num);
    void closeObject();
    void Close();
};


#endif //ABWORLD_EXPORT_H
