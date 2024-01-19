#include <iostream>

class car
{
protected:
    std::string m_model;
    std::string m_maker;
    int m_displacement;
    int m_ps;
    int m_weight;

public:
    car(const std::string &md, const std::string &mk, int dp, int p, int w)
        : m_model(md), m_maker(mk), m_displacement(dp), m_ps(p), m_weight(w)
    {
        std::cout << "car constructor: " << m_model << std::endl;
    }

    ~car()
    {
        std::cout << "car destructor: " << m_model << std::endl;
    }

    std::string model() const { return m_model; }

    int no() const
    {
        if (m_displacement < 2000)
            return 5;
        else
            return 3;
    }

    double pwratio() const
    {
        return (double)m_weight / (double)m_ps;
    }

    int tax() const
    {
        if (m_displacement <= 1000)
            return 29500;
        else if (m_displacement <= 1500)
            return 34500;
        else if (m_displacement <= 2000)
            return 39500;
        else if (m_displacement <= 2500)
            return 45000;
        else if (m_displacement <= 3000)
            return 51000;
        else if (m_displacement <= 3500)
            return 58000;
        else if (m_displacement <= 4000)
            return 66500;
        else if (m_displacement <= 4500)
            return 76500;
        else if (m_displacement <= 6000)
            return 88000;
        else
            return 110000;
    }
};

class hybrid_car : public car
{
private:
    int m_motor_ps;

public:
    hybrid_car(const std::string &md, const std::string &mk,
               int dp, int p, int w, int mps)
        : car(md, mk, dp, p, w), m_motor_ps(mps)
    {
        std::cout << "hybrid_car constructor: " << md << std::endl;
    }

    hybrid_car()
        : car("DefaultModel", "DefaultMaker", 0, 0, 0), m_motor_ps(0)
    {
        std::cout << "hybrid_car default constructor" << std::endl;
    }

    ~hybrid_car()
    {
        std::cout << "hybrid_car destructor: " << m_model << std::endl;
    }

    double pwratio() const
    {
        return (double)m_weight / (double)(m_ps + m_motor_ps);
    }

    int tax() const
    {
        return 0;
    }
};

int main()
{
    car a = car("Skyline", "Nissan", 3498, 272, 1500);
    car b = car("Civic", "Honda", 1998, 215, 1190);
    hybrid_car h = hybrid_car("Prius", "Toyota", 1496, 77, 1290, 68);

    std::cout << a.model() << "  " << a.no() << "  " << a.pwratio() << "  " << a.tax() << std::endl;
    std::cout << b.model() << "  " << b.no() << "  " << b.pwratio() << "  " << b.tax() << std::endl;
    std::cout << h.model() << " " << h.no() << " " << h.pwratio() << " " << h.tax() << std::endl;

    return 0;
}
