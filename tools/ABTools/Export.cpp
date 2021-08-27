//
// Created by desuex on 26.05.2020.
//

#include "Export.h"

void Export::openFileToSave(const QString &filename) {
    file.open(filename.toStdString(), std::ofstream::out | std::ofstream::trunc);
//    file.open(filename, std::ios_base::app);
}

void Export::putTabs() {

    for (int i = 0; i < tabs; i++) {
        file << "\t";
    }
}

void Export::Close() {
    file.close();

}

void Export::writeLine(const QString &key, const QString &value) {
    putTabs();
//    QString str = value;
//    str.toStdString().erase(std::find_if(str.rbegin(), str.rend(), [](int character) {
//        return '\0' != character;
//    }).base(), str.end());
    file << key.toStdString() << "=" << value.toStdString() << std::endl;
}

void Export::writeLine(const QString &key, const uint16_t &value) {
    putTabs();
    file << key.toStdString() << "=" << value << std::endl;
}

void Export::writeLine(const QString &key, const uint32_t &value) {
    putTabs();
    file << key.toStdString() << "=" << value << std::endl;
}

void Export::writeLineHex(const QString &key, const uint32_t &value) {
    putTabs();
    file << key.toStdString() << "=" << std::hex << value << std::endl;
}

void Export::writeLine(const QString &key, float value) {
    putTabs();
    file << key.toStdString() << "=" << value << std::endl;
}

void Export::openObject(const QString &name) {
    putTabs();
    file << name.toStdString() << " {" << std::endl;
    tabs++;
}

void Export::openObject(int num) {
    putTabs();
    file << std::dec << num << " {" << std::endl;
    tabs++;
}

void Export::closeObject() {
    if (tabs > 0) {
        tabs--;
    }
    putTabs();
    file << "}" << std::endl;

}

void Export::writeLine(const QString &key, int value) {
    putTabs();
    file << key.toStdString() << "=" << std::dec << value << std::endl;
}

void Export::writeLine(const QString &key, bool value) {
    putTabs();
    file << key.toStdString() << "=" << (value ? "True" : "False") << std::endl;
}
