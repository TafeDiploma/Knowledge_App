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
	std::string contents;
	std::ifstream file(dir.toStdString(), std::ifstream::in | std::ifstream::binary );

	// Error checking.
	if (!file)
		return QString();

	// Get length of file.
	file.seekg(0, file.end);
	contents.resize(file.tellg());

	// Reset pos.
	file.seekg(0, file.beg);

	// Read from file.
	file.read(&contents[0], contents.size());
	file.close();

	return QString::fromStdString(contents);
}

bool utils::writeBinaryFile(const QString & dir, const QString& text)
{
	std::ofstream file;
	file.open(dir.toStdString(), std::ofstream::out | std::ofstream::binary);

	if (!file)
		return false;

	file << text.toStdString();
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