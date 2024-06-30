#include<iostream>
#include<vector>
using namespace std;




class General
{
private:

    string name;
    string causes;
    string treatment;
    vector<string> symptoms;

public:

    General(string name,string causes, string treatment, vector<string> symptoms)
            :name(name),causes(causes), treatment(treatment), symptoms(symptoms) {}

    string getName()const
    {
        return name;
    }

    string getCauses()const
    {
        return causes;
    }

    string getTreatment()const
    {
        return treatment;
    }

    vector<string> getSymptoms()const
    {
        return symptoms;
    }
};



class detailofdisease : public General
{
public:
    detailofdisease(string causes, string treatment, vector<string> symptoms)
            : General({},causes, treatment, symptoms) {}
};

class Typeofdisease: public General
{

private:
    vector<detailofdisease> Typess;


public:
    Typeofdisease(string name,vector<detailofdisease> Typess)
            :General(name,"","",{}), Typess(Typess){}

    vector<detailofdisease> gettype()const
    {
        return Typess;
    }

};

class Disease
{
protected:
    string name;
    string description;
    vector<Typeofdisease> typeofdisease;

public:
    Disease(string name, string description, vector<Typeofdisease> typeofdisease)
            : name(name), description(description), typeofdisease(typeofdisease) {}


    string getName()const
    {
        return name;
    }

    string getDescription()const
    {
        return description;
    }

    virtual vector<Typeofdisease> gettypeofdisease() const = 0;

    virtual void Detail()const
    {
        cout<<"\nDisease: "<<name<<"\nDescription: "<<description<<endl;

        for(size_t i=0; i<typeofdisease.size(); i++)
        {
            cout<<"*Type of Disease: "<<typeofdisease[i].getName();



            vector<detailofdisease> Typess = typeofdisease[i].gettype();

            for(size_t j=0;  j<Typess.size(); j++)
            {

                cout<<"\n   -Causes: "<<Typess[i].getCauses();
                cout<<"\n   -Treatment: "<<Typess[i].getTreatment();
                vector<string> symptoms = Typess[i].getSymptoms();
                for (size_t k=0; k<symptoms.size(); k++){
                    cout<<"\n   -Symptoms: "<<symptoms[k];
                }

                cout<<"\n---------------------------------"<<endl;
            }
        }
    }

};

class Flu : public Disease
{
public:
    Flu()
            : Disease("Flu", "Respiratory Infection Causes Fever",
                             {

                                     Typeofdisease("Influenza A,B,C",
                                                {
                                                        detailofdisease("Viral Mutation","Antiviral Medication", {"Fever, Fatigue"}),

                                                })
                             }) {}

    vector<Typeofdisease> gettypeofdisease() const override
    {
        return typeofdisease;
    }
};


class Diabetes : public Disease
{
public:
    Diabetes()
            : Disease("Diabetes", "Body Cannot Properly Regulate Blood Sugar.",
                             {

                                     Typeofdisease("INfectious Disease",
                                                {
                                                        detailofdisease( "Genetic Factor","Insuline-Therapy", {"Frequent Urination, Extreme Hunger"}),

                                                })
                             }) {}

    vector<Typeofdisease> gettypeofdisease() const override
    {
        return typeofdisease;
    }
};

class Asthma : public Disease
{
public:
    Asthma()
            : Disease("Asthma", "Shortness of Breath, Chest tightness.",
                             {

                                     Typeofdisease("Allergic Asthma",
                                                {
                                                        detailofdisease("Dust Mites", "Avoidence of Triggers", {"Wheezing, Caughing"}),

                                                })
                             }) {}

    vector<Typeofdisease> gettypeofdisease() const override
    {
        return typeofdisease;
    }
};




int main()
{

    Flu flu;
    flu.Detail();

    Diabetes diabetes;
    diabetes.Detail();

    Asthma asthma;
    asthma.Detail();

    return 0;

}
