#ifndef PIDMAP_H
#define PIDMAP_H

#include <fstream>
#include <map>
#include <vector>

class pidmap
{
    class pidinfo {
    public:
        unsigned int nb_packet;
        bool has_pcr;
        bool has_pts;
        bool has_dts;
        char pattern;
        float percent;
    };

    // pid map
    std::map<unsigned int, pidinfo> m_pidMap;

    // pid vec
    std::vector<unsigned int> m_pidVec;

    std::ifstream& m_fileIn;

public:
    pidmap(std::ifstream& fileIn);
    ~pidmap();

    bool run(unsigned int NbPacket = (unsigned int)-1);

    void getPcrPid(std::vector<unsigned int>& pidVector);
    void getPtsPid(std::vector<unsigned int>& pidVector);
    void getDtsPid(std::vector<unsigned int>& pidVector);

    void OutPid();
    void OutMap();
};

#endif // PIDMAP_H
