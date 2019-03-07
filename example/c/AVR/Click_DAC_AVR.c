/*
Example for DAC Click

    Date          : Jul 2018.
    Author        : Nenad Filipovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes CS pin as OUTPUT, SPI and LOG.
- Application Initialization - Initializes Driver enable's SPI and LOG.
- Application Task - (code snippet) In this example the DAC click communicates with MCU through the SPI communicationand and send:
1. data procentage value ( form 0 to 100 with step 20 [%]),
2. data 12-bit value ( form 0 to 4095 with step 1000 ),
and transforms it to the output voltage, ranging from 0 to Vref [mV]

Additional Functions :

- SPI
- UART
- Conversion

*/

#include "Click_DAC_types.h"
#include "Click_DAC_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_DAC_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    dac_spiDriverInit( (T_DAC_P)&_MIKROBUS1_GPIO, (T_DAC_P)&_MIKROBUS1_SPI );

    mikrobus_logWrite("          Initialisation",_LOG_LINE);
    mikrobus_logWrite( "##################################", _LOG_LINE );
    mikrobus_logWrite("----------------------------------", _LOG_LINE);
}

void applicationTask()
{
    char strDACValue[ 15 ];
    char strOutputVoltage[ 15 ];
    uint32_t valueDAC;
    uint8_t valueDACPct;

    mikrobus_logWrite("    ~ DAC Percentage Value ~",_LOG_LINE);
    mikrobus_logWrite("----------------------------------", _LOG_LINE);

    for ( valueDACPct = 0; valueDACPct < 101; valueDACPct += 20 )
    {
        dac_setOutputVoltageProcentage( valueDACPct );

        LongToStr( valueDACPct, strDACValue );

        mikrobus_logWrite( " Current DAC Value:", _LOG_TEXT );
        mikrobus_logWrite( strDACValue, _LOG_TEXT );
        mikrobus_logWrite( " %", _LOG_LINE );

        LongToStr( ( valueDACPct ) * 33 , strOutputVoltage );

        mikrobus_logWrite( " Output Voltage: ~ ", _LOG_TEXT );
        mikrobus_logWrite( strOutputVoltage, _LOG_TEXT );
        mikrobus_logWrite( " mV", _LOG_LINE );
        mikrobus_logWrite( "----------------------------------", _LOG_LINE );

        Delay_ms( 5000 );
    }

    mikrobus_logWrite( "##################################", _LOG_LINE );
    mikrobus_logWrite( "----------------------------------", _LOG_LINE );
    Delay_1sec();

    mikrobus_logWrite("    ~ DAC 12-bit Data Value ~",_LOG_LINE);
    mikrobus_logWrite("----------------------------------", _LOG_LINE);

    for ( valueDAC = 0; valueDAC < 4096; valueDAC += 1000 )
    {
        dac_setOutVoltage( valueDAC );

        LongToStr( valueDAC, strDACValue );

        mikrobus_logWrite( " Current DAC Value:", _LOG_TEXT );
        mikrobus_logWrite( strDACValue, _LOG_LINE );

        LongToStr( ( ( valueDAC ) * 220 ) / 273 , strOutputVoltage );

        mikrobus_logWrite( " Output Voltage: ~ ", _LOG_TEXT );
        mikrobus_logWrite( strOutputVoltage, _LOG_TEXT );
        mikrobus_logWrite( " mV", _LOG_LINE );
        mikrobus_logWrite( "----------------------------------", _LOG_LINE );

        Delay_ms( 5000 );
    }

    mikrobus_logWrite( "##################################", _LOG_LINE );
    mikrobus_logWrite( "----------------------------------", _LOG_LINE );
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}