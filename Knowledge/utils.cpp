#include "utils.h"
#include <sys/stat.h>
#include <stdio.h>

#include <QDebug>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QVector>
#include <QException>
#include <fstream>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include <string>
#include <vector>
#include <QChar>
#include <QDateTime>
#include <chrono>
#include <ctime>
#include <cstring>

QString utils::readFile(const QString& directory)
{
	QString val = QString();
	try
	{
		QFile file(directory);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return QString();

		val = file.readAll();
		file.close();
	}
	catch (QException::exception ex)
	{
		qDebug() << ex.what();
	}

	return val;
}

QString utils::readBinaryFile(const QString& dir)
{
	return QString::fromStdString(readBinaryFileStd(dir.toStdString()));
}

std::string utils::readBinaryFileStd(const std::string & dir)
{
	std::string contents;
	std::ifstream file(dir, std::ifstream::in | std::ifstream::binary);

	// Error checking.
	if (!file)
		return std::string();

	// Get length of file.
	file.seekg(0, file.end);
	contents.resize(file.tellg());

	// Reset pos.
	file.seekg(0, file.beg);

	// Read from file.
	file.read(&contents[0], contents.size());
	file.close();

	return contents;
}

bool utils::writeBinaryFile(const QString & dir, const QString& text)
{
	return writeBinaryFileStd(dir.toStdString(), text.toStdString());
}

bool utils::writeBinaryFileStd(const std::string & dir, const std::string & text)
{
	std::ofstream file;
	file.open(dir, std::ofstream::out | std::ofstream::binary);

	if (!file)
		return false;

	file << text;
	file.close();

	return true;
}

QString utils::accessFileRandomly(const QString& dir, const size_t& pos, const int& way)
{
	std::string contents;
	std::ifstream file(dir.toStdString(), std::ifstream::in | std::ifstream::binary);

	// Error checking.
	if (!file)
		return QString();

	file.seekg(pos, way);
	std::getline(file, contents);
	file.close();

	return QString::fromStdString(contents);
}

QString utils::accessFileRandomly(const QString& dir, const size_t& pos)
{
	return accessFileRandomly(dir, pos, std::ifstream::beg);
}

bool utils::fileExists(const QString & name)
{
	struct stat buffer;
	return (stat(name.toStdString().c_str(), &buffer) == 0);
}

utils::CompQJsonObjectBy utils::compareQJsonObjectBy(const QString& hashIndex)
{
	CompQJsonObjectBy s;
	s.hashIndex = hashIndex;
	return s;
}

tm utils::currentDateTime()
{
	time_t     now = time(0);
	return *localtime(&now);
}

void utils::LogError(const std::string& des, const std::exception& ex)
{
	// Method attr.
	std::ofstream file;
	std::string fileName;
	char buf[80];

	// Getting current date time, and formatting it as only date.
	strftime(buf, sizeof(buf), "%Y-%m-%d", &utils::currentDateTime());

	// File name.
	fileName = "CaughtExceptions" + std::string(buf) + ".txt";

	// Openging file.
	file.open(fileName, std::ofstream::app);

	// Getting current date time and formatting it as only time.
	strftime(buf, sizeof(buf), "%X", &utils::currentDateTime());

	// Appending dump into text file.
	file << "\n" << std::string(buf) << " - " << des << ex.what();
}

void utils::LogError(const std::exception& ex)
{
	utils::LogError("", ex);
}

void utils::QLogError(const QString& des, const QException& ex)
{
	utils::LogError(des.toStdString(), ex);
}

void utils::QLogError(const QException& ex)
{
	utils::LogError(ex);
}
