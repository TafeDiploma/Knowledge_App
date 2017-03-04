#pragma once

#include <QDebug>
#include <QJsonObject>
#include <QString>

class utils
{
private:
	/// <summary>
	/// Compare QJsonObject by struct.
	/// </summary>
	struct CompQJsonObjectBy
	{
		QString hashIndex;
		bool operator() (const QJsonObject& lhs, const QJsonObject& rhs)
		{
			return lhs[hashIndex].toString() < rhs[hashIndex].toString();
		}
	};

public:
	/// <summary>
	/// Question batch object.
	/// </summary>
	struct QuestionBatch
	{
		QString title;
		QString description;
		size_t bIndex;
	};

	/// <summary>
	/// Compare Question batch object by title struct.
	/// </summary>
	struct CompQuestionBatchByTitle
	{
		bool operator() (const utils::QuestionBatch& lhs, const utils::QuestionBatch& rhs)
		{
			return lhs.title < rhs.title;
		}
	};

	/// <summary>
	/// Compare Question batch object by title struct.
	/// For binary search.
	/// </summary>
	struct CompQuestionBatchByTitleBSearch
	{
		bool operator() (const QString& s, const utils::QuestionBatch& i)
		{
			return s < i.title;
		}

		bool operator() (const utils::QuestionBatch& i, const QString& s)
		{
			return i.title < s;
		}
	};

	/// <summary>
	/// Compare QJSonObject to string by title struct.
	/// For binary search.
	/// </summary>
	struct CompQJsonObjectToStringByTitle
	{
		bool operator() (const QString& s, const QJsonObject& i)
		{
			return s < i["title"].toString();
		}

		bool operator() (const QJsonObject& i, const QString& s)
		{
			return i["title"].toString() < s;
		}
	};

	/// <summary>
	///	Read file method.
	/// </summary>
	static QString readFile(const QString& directory);

	/// <summary>
	/// Method to read binary file from location directory passed.
	/// </summary>
	/// <param name="dir"></param>
	/// <returns>All text within file as string</returns>
	static QString readBinaryFile(const QString& dir);

	/// <summary>
	/// Method to write binary file from location directory passed.
	/// </summary>
	/// <param name="dir"></param>
	/// <param name="text"></param>
	/// <returns>Bool if error produced.</returns>
	static bool writeBinaryFile(const QString& dir, const QString& text);

	/// <summary>
	/// Method to access file randomly.
	/// </summary>
	/// <param name="dir"></param>
	/// <param name="pos"></param>
	/// <param name="way"></param>
	/// <returns></returns>
	static QString accessFileRandomly(const QString& dir, const size_t& pos, const int& way);

	/// <summary>
	/// Method to access file randomly with only directory and position.
	/// </summary>
	/// <param name="dir"></param>
	/// <param name="pos"></param>
	/// <param name="way"></param>
	/// <returns></returns>
	static QString accessFileRandomly(const QString& dir, const size_t& pos);

	/// <summary>
	/// Check if file exists within directory passed.
	/// </summary>
	/// <param name="name"></param>
	/// <returns>Bool if file exits.</returns>
	static bool fileExists(const QString& name);

	/// <summary>
	/// Method to compare QJsonObject by hash value with
	/// the index of the string value passed.
	/// </summary>
	/// <param name="hashIndex"></param>
	/// <returns></returns>
	static CompQJsonObjectBy compareQJsonObjectBy(const QString& hashIndex);
	
	/// <summary>
	/// Quicksort algorithm method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template<typename Iterator>
	static inline void quickSort(Iterator begin, Iterator end)
	{
		if (end - begin < 2)
			return;
		Iterator l = begin;
		Iterator r = end - 1;
		
		// find pivot.
		Iterator pivot = std::next(begin, (std::distance(begin, end) / 2));

		while (l != r)
		{
			// Find the lowest bound number to swap.
			while (*l < *pivot) 
				++l;
			while (*r >= *pivot && l < r) 
				--r;

			// Do the swap.
			if (pivot == l) 
				pivot = r;
			std::swap(*l, *r);
		}

		// Move pivot to the position.
		std::swap(*pivot, *l);

		// Sort left.
		quickSort(begin, l);
		// Sort right.
		quickSort(l + 1, end);
	};

	/// <summary>
	/// Binary search algorithm method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template<typename Iterator, class T>
	static inline Iterator binarySearch(Iterator begin, Iterator end, T value)
	{
		Iterator left = begin;
		Iterator right = end;
		while (left <= right) 
		{
			Iterator middle = std::next(left, (std::distance(left, right) / 2));
			if (*middle == value)
				return middle;
			else if (*middle > value)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return nullptr;
	}

	/// <summary>
	/// Print all elements of simple array method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template <class Iterator>
	static inline void printArray(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			qDebug() << *begin << ' ';
			++begin;
		}
		qDebug() << "\n";
	};

	/// <summary>
	/// Print all reference of simple array method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template <class Iterator>
	static inline void printArrayReference(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			qDebug() << begin << ' ';
			++begin;
		}
		qDebug() << "\n";
	};

	/// <summary>
	/// Copy over reference of array to pointer method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	/// <param name="arr"></param>
	template <class RAI, class T>
	static inline void copyOverReference(RAI begin, RAI end, T& arr)
	{
		size_t index = 0;
		while (begin != end)
		{
			arr[index] = begin;
			++begin;
			index++;
		}
	};
private:
};

