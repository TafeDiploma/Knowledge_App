#include "utils.h"

#include <QDebug>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QException>
#include <fstream>
#include <ostream>
#include <string>
#include <sys/stat.h>

/// <summary>
///	Read file method.
/// </summary>
QString utils::readFile(const QString& directory)
{
	QString val = QString();
	try
	{
		QFile file(directory);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			return QString();
		}

		val = file.readAll();
		file.close();
	}
	catch (QException::exception ex)
	{
		qDebug() << ex.what();
	}

	return val;
}

/// <summary>
/// Method to read binary file from location directory passed,
/// and return all text within.
/// </summary>
/// <param name="dir"></param>
/// <returns>All text within file as string</returns>
QString utils::readBinaryFile(const QString& dir)
{
	// TODO: Make this better.
	QString output;
	std::ifstream inf;
	inf.open(dir.toStdString(), std::ios::in | std::ios::binary);
	if (inf)
	{
		std::string contents;

		inf.seekg(0, std::ios::end);
		contents.resize(inf.tellg());
		inf.seekg(0, std::ios::beg);
		inf.read(&contents[0], contents.size());
		inf.close();
		output = QString::fromStdString(contents);
	}
	return output;
}

/// <summary>
/// Method to compare QJsonObject by hash value with
/// the index of the string value passed.
/// </summary>
/// <param name="hashIndex"></param>
/// <returns></returns>
utils::myStruct utils::compareQJsonObjectBy(const QString& hashIndex)
{
	myStruct s;
	s.hashIndex = hashIndex;
	return s;
}