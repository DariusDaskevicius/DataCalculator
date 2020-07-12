#include <vector>
#include <string>

class HandleDates
{
public:
	/**
	 * @brief Constructor, sets begin and end dates
	 * @param begin - begin date
	 * @param end - end date
	 */
	HandleDates(const std::string& begin, const std::string& end);
	/**
	 * @brief Calculates difference Y,M,D dates
	 */
	void calcDates();
	/**
	 * @brief Returns years difference
	 * should be called after calculation of all dates (method calcDates())
	 */
	int getDifDays() const;
	/**
	* @brief Returns months difference
	* should be called after calculation of all dates (method calcDates())
	*/
	int getDifMonths() const;
	/**
	* @brief Returns days difference
	* should be called after calculation of all dates (method calcDates())
	*/
	int getDifYears() const;

	int calcDays();
	int yearsFunc();
	int monthFunc();

private:
	std::vector<int> Split(const std::string& s, char delim);
	void DataSplit(const std::string& begin, const std::string& end);
	int CalculateYears();
	int CalculateMonths();
	int CalcultaeDays();
	int getCoef();
	bool isLoopYear(int year);
	bool devidesTo4(int year);
	bool devidesTo100(int year);
	bool devidesTo400(int year);

	int eDays;
	int eMonths;
	int eYears;
	int bDays;
	int bMonths;
	int bYears;

	int difYears;
	int difMonths;
	int difDays;
};

