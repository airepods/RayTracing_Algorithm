#ifndef CONE_H    
#define CONE_H

#include "surface.h"
#include "geometry/intersection.h"
#include <string>

namespace rtm
{
class Cone : public Surface
{
    private:
        double m_minimum;
        double m_maximum;
        bool m_closed;
    public:
        Cone();
        Cone(double minimum, double maximum, bool closed = false);
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;

        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Cone";}
    private:
        void intersect_caps(const Ray& r, std::vector<Intersection>& xs) const;
        bool check_cap(const Ray& r, const double& t, const double& y_cap) const;

};
} // namespace rtm


#endif