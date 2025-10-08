
// DiagnosticReport header file

#ifndef DIAGNOSTIC_REPORT_H
#define DIAGNOSTIC_REPORT_H
#include<vector>
#include"Ashwin_Mahajan_Oct08_Task1_SensorReading.h"
#include"Ashwin_Mahajan_Oct08_Task1_SeverityLevel.h"

// class diagnostic report
class DiagnosticReport{
    private:
        std::vector<SensorReading> collection; // collection to store Sensor Reading object
    
    public:
        void addSensorReading(const SensorReading& );
        void displayAllReadings() const;
        int getReadingsCountBySeverity(SeverityLevel ) const;
        SensorReading* filterBySeverity(SeverityLevel level, int& count)const;
        void sortBySeverityDescending();
        static bool compareSeverity(const SensorReading&, const SensorReading&);
        void severityMap() const;
        SensorReading* findReadingByName(const std::string& name);
};

#endif