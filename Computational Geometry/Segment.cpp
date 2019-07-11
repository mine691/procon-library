struct Segment : Line
{
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

using segments = vector<Segment>;
