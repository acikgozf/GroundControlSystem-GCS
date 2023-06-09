#ifndef UAV_SETTINGS_H
#define UAV_SETTINGS_H



/*--- UAV durumu gunceller ve uygun mesajlari goderir.
 *--- Uav durumu: pitch,roll,yaw gibi..
 */


#include <QObject>

class Uav_settings : public QObject
{
    Q_OBJECT
public:
    explicit Uav_settings(QObject *parent = nullptr);

    float lipopillfull;
    float lipopillbos;

    void setAccX(float value);
    void setAccY(float value);
    void setAccZ(float value);
    void setRoll(float value);
    void setPitch(float value);
    void setYaw(float value);


    void setAbsBasinc(float value);
    void setDiffBasinc(float value);
    void setBasincAlt(float value);
    void setSicaklik(float value);





public slots:



protected:



signals:


private:





};

#endif // UAV_SETTINGS_H
