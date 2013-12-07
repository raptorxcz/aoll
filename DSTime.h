//
//  DSTime.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSTime__
#define __ims__DSTime__

#include <iostream>
#include "DSBlock.h"

// Trida pro cas a manipulaci s nim.
class DSTime : public DSBlock
{
    // Aktualni cas.
    double currentTime;
    // Aktualni cas ktery neni modifikovan.
    double baseTime;
    double startTime;
    double endTime;
    double step;
    double baseStep;
    double running;
    double minStep;
    double maxStep;
    
public:
    DSTime(double aStartTime, double anEndTime, double aStep):
    startTime(aStartTime), endTime(anEndTime), step(aStep), baseStep(step)
    {
        if(anEndTime <= aStartTime)
            running = false;
        else
            running = true;
        
        currentTime = startTime;
        baseTime = startTime;
        minStep = 1e-5;
        maxStep = 1e-2;
    }
    // Zviseni casu o krok
    bool incrementTime();
    // Sjednoceni casu na cas ktery nebyl ovlivnen
    void clear();
    
    // Lze provest dalsi krok
    bool isCurrentTimeValid();
    
    // Vraci hodnotu casu.
    virtual double value();
    
    // Velikost kroku.
    double getStep();
    
    //Nastavi aktualni cas na danou hodnotu.
    void setTime(double time);
    
    // Udela krok zpet.
    void stepBack();
    
    // Nastavi docasnou velikost kroku
    void setStep(double aStep);
    
    // Nastavi velikost kroku
    void setBaseStep(double aStep) {baseStep = aStep;};
    
    // Nastavi docasny krok na hodnotu kroku.
    void clearStep();
    
    // Vraci minimalni velikost kroku.
    double getMinStep(){ return minStep; }
    
    // Vraci maximalni velikost kroku.
    double getMaxStep(){ return maxStep; }
    
    // Nastavi minimalni a maximalni velikost kroku.
    void setMinMaxStep(double min, double max){
        minStep = min;
        maxStep = max;
    }
};

extern DSTime t;

#endif /* defined(__ims__DSTime__) */
