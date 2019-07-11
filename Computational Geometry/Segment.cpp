//need Line
struct Segment : Line
{
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

using segments = vector<Segment>;

Point CrossPoint(const Segment &s, const Segment &t)
{
    return CrossPoint(Line(s), Line(t));
}
