![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# DAC Click

---

- **CIC Prefix**  : DAC
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Jul 2018.

---

### Software Support

We provide a library for the DAC Click on our [LibStock](https://libstock.mikroe.com/projects/view/209/dac-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This is a sample program which demonstrates the use of the Microchip's MCP4921 12-bit D/A converter. 
This device accepts digital input (number from 0..4095 or procentage value from 0..100 %) and transforms it to the output voltage, ranging from 0..Vref
and display log via UART. In this example the DAC communicates with MCU through the SPI communication.

Key functions :

- ``` void dac_setOutVoltage( uint16_t valueDAC ) ``` - Generic 12-bit data write function
- ``` void dac_setOutputVoltageProcentage( uint8_t valueDACPct ) ``` - Function write procentage value

**Examples Description**


The application is composed of three sections :

- System Initialization - Initializes CS pin as OUTPUT, SPI and LOG.
- Application Initialization - Initializes Driver enable's SPI and LOG.
- Application Task - (code snippet) In this example the DAC click communicates with MCU through the SPI communicationand and send:
1. data procentage value ( form 0 to 100 with step 20 [%]),
2. data 12-bit value ( form 0 to 4095 with step 1000 ),
and transforms it to the output voltage, ranging from 0 to Vref [mV]


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/209/dac-click-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversion

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
