// s is only 'a' and 'b'
vector<int> Run_length_coding(string s)
{
    int N = s.size();
    vector<int> Len;

    Len.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int l = Len.size() - 1;
        if ((s[i] == 'a' && l % 2 == 0) || (s[i] == 'b' && l % 2 == 1))
        {
            Len[l]++;
        }
        else
        {
            Len.push_back(1);
        }
    }
    return Len;
}
