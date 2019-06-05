#ifndef __NRF24L01P_H__
#define __NRF24L01P_H__

#define NRF24L01P_TX_PWR_ZERO_DB         0
#define NRF24L01P_TX_PWR_MINUS_6_DB     -6
#define NRF24L01P_TX_PWR_MINUS_12_DB   -12
#define NRF24L01P_TX_PWR_MINUS_18_DB   -18

#define NRF24L01P_DATARATE_250_KBPS    250
#define NRF24L01P_DATARATE_1_MBPS     1000
#define NRF24L01P_DATARATE_2_MBPS     2000

#define NRF24L01P_CRC_NONE               0
#define NRF24L01P_CRC_8_BIT              8
#define NRF24L01P_CRC_16_BIT            16

#define NRF24L01P_MIN_RF_FREQUENCY    2400
#define NRF24L01P_MAX_RF_FREQUENCY    2525

#define NRF24L01P_PIPE_P0                0
#define NRF24L01P_PIPE_P1                1
#define NRF24L01P_PIPE_P2                2
#define NRF24L01P_PIPE_P3                3
#define NRF24L01P_PIPE_P4                4
#define NRF24L01P_PIPE_P5                5


#define DEFAULT_NRF24L01P_ADDRESS       ((unsigned long long) 0xE7E7E7E7E7 )
#define DEFAULT_NRF24L01P_ADDRESS_WIDTH  5
#define DEFAULT_NRF24L01P_CRC            NRF24L01P_CRC_8_BIT
#define DEFAULT_NRF24L01P_RF_FREQUENCY  (NRF24L01P_MIN_RF_FREQUENCY + 2)
#define DEFAULT_NRF24L01P_DATARATE       NRF24L01P_DATARATE_1_MBPS
#define DEFAULT_NRF24L01P_TX_PWR         NRF24L01P_TX_PWR_ZERO_DB
#define DEFAULT_NRF24L01P_TRANSFER_SIZE  4

class nRF24L01P {

public:

    nRF24L01P(PinName mosi, PinName miso, PinName sck, PinName csn, PinName ce, PinName irq = NC);

    void setRfFrequency(int frequency = DEFAULT_NRF24L01P_RF_FREQUENCY);

    int getRfFrequency(void);

    void setRfOutputPower(int power = DEFAULT_NRF24L01P_TX_PWR);

    int getRfOutputPower(void);

    void setAirDataRate(int rate = DEFAULT_NRF24L01P_DATARATE);

    int getAirDataRate(void);

    void setCrcWidth(int width = DEFAULT_NRF24L01P_CRC);

    int getCrcWidth(void);

    void setRxAddress(unsigned long long address = DEFAULT_NRF24L01P_ADDRESS, int width = DEFAULT_NRF24L01P_ADDRESS_WIDTH, int pipe = NRF24L01P_PIPE_P0);

    void setRxAddress(unsigned long msb_address, unsigned long lsb_address, int width, int pipe = NRF24L01P_PIPE_P0);

    void setTxAddress(unsigned long long address = DEFAULT_NRF24L01P_ADDRESS, int width = DEFAULT_NRF24L01P_ADDRESS_WIDTH);

    void setTxAddress(unsigned long msb_address, unsigned long lsb_address, int width);

    unsigned long long getRxAddress(int pipe = NRF24L01P_PIPE_P0);

    unsigned long long getTxAddress(void);

     void setTransferSize(int size = DEFAULT_NRF24L01P_TRANSFER_SIZE, int pipe = NRF24L01P_PIPE_P0);

    int getTransferSize(int pipe = NRF24L01P_PIPE_P0);


    bool getRPD(void);

    void setReceiveMode(void);

    void setTransmitMode(void);

    void powerUp(void);

    void powerDown(void);

    void enable(void);

    void disable(void);

    int write(int pipe, char *data, int count);
    
    int read(int pipe, char *data, int count);

    bool readable(int pipe = NRF24L01P_PIPE_P0);

    void disableAllRxPipes(void);
    
    void disableAutoAcknowledge(void);
    
    void enableAutoAcknowledge(int pipe = NRF24L01P_PIPE_P0);
    
    void disableAutoRetransmit(void);
    
    void enableAutoRetransmit(int delay, int count);

private:

    int getRegister(int regAddress);

    void setRegister(int regAddress, int regData);

    int getStatusRegister(void);

    SPI         spi_;
    DigitalOut  nCS_;
    DigitalOut  ce_;
    InterruptIn nIRQ_;

    int mode;

};

#endif /* __NRF24L01P_H__ */
