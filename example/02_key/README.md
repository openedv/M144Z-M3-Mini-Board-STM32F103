## Key example<a name="catalogue"></a>

### 1 Brief
The main function of this code is to toggle the status of LED0 when the KEY0 button is pressed and toggle the status of LED1 when the WKUP button is pressed.
### 2 Hardware Hookup
The hardware resources used in this example are:
+ LED0 - PB5
+ LED1 - PE5
+ KEY - WKUP(PA0)
+ KEY - KEY0(PE4) 

The schematic diagram is as follows:

<img src="../../1_docs/3_figures/02_key/01-sch.png">

<img src="../../1_docs/3_figures/02_key/02_sch.png">

As shown in the figure above, **KEY0** and **WKUP** are respectively connected to **PE4** and **PA0** of the MCU. It should be noted here that WKUP and KEY0 are both "high" active, and there is no external pull-down resistor, so you need to set the pull-down inside the STM32F103 to determine the setting of the idle level state.

The position of KEY in the Mini board is shown in the following figure:

<img src="../../1_docs/3_figures/02_key/03_position.png">

### 3 STM32CubeIDE Configuration

Here we will explain how to configure KEY example in the STM32CubeIDE. First of all, we make a copy of the example in the previous chapter, as shown in the figure below:

<img src="../../1_docs/3_figures/02_key/04_copy.png">

Then click on the blank space on the right, paste the project, and name the project ``02_key``, as shown below:

<img src="../../1_docs/3_figures/02_key/05_paste.png">

We can see that a new project file will appear on the right, but its.ioc file name is inconsistent with the project file name, so double-clicking the.ioc file cannot be opened normally, we need to rename the **.ioc** file:

<img src="../../1_docs/3_figures/02_key/06_rename.png">

In this way, we can get a new project ``02_key``, which inherits all the configurations of the previous chapter, on this basis, add functions related to the KEY, so as to avoid repeating the configuration of the LED part and the system clock part, which can greatly improve the efficiency.
Then we double-click **02_key.ioc** to enter the STM32CubeMX tool, and configure PA0 and PE4 at the IO port of the KEY pin to the mode of **GPIO_Input**.

<img src="../../1_docs/3_figures/02_key/07_gpio.png">

Click **System Core > GPIO** , and the result of pin configuration is as shown in the figure below:

<img src="../../1_docs/3_figures/02_key/08_config.png">


Click **File > Save**, and you will be asked to generate code.Click **Yes**.

##### code
Then we add the key driver file *key.c/key.h* in the BSP folder. We show the code of key.c here.

###### key.c

```c#
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;                /* Press the button to release the flag */
    uint8_t keyval = 0;

    if (mode == 1)
    {
    	key_up = 1;                           /* support for linking */
    }

    if (key_up && (KEY0 == 1 || WK_UP == 1))  /* The key release flag is 1, and any key is pressed */
    {
    	HAL_Delay(10);                        /* delay 10ms */
        key_up = 0;

        if (KEY0 == 1)
        {
            keyval = KEY0_PRES;
        }

        if (WK_UP == 1)
        {
            keyval = WKUP_PRES;
        }
    }
    else if (KEY0 == 0 && WK_UP == 0)         /* Without any key pressed, the marker key is released */
    {
        key_up = 1;
    }

    return keyval;                            /* return key value */
}
```
The function above realizes the key scan and has the function of eliminating the shake of the key.
##### main.c
Open up main.c, and modify it to look like the following: 
```c#
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t key;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    key = key_scan(0);            /* scan key */
    switch (key)
    {
        case KEY0_PRES:           /* KEY0 is pressed */
        {
            LED0_TOGGLE();        /* LED0 state is flipped */
            break;
        }
        case WKUP_PRES:           /* WKUP is pressed */
        {
            LED1_TOGGLE();        /* LED1 state is flipped */
            break;
        }
        default:
        {
            break;
	  	}
	  	HAL_Delay(10);            /* delay 10ms */
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```
The above code calls the key scan function every 10 milliseconds to scan the status of the key.

### 4 Running
#### 4.1 Compile & Download
After the compilation is complete, connect the DAP and the Mini Board, and then connect to the computer together to download the code to the Mini Board.
#### 4.2 Phenomenon
Press the **RESET** button to begin running the program on your Mini Board, and observe that the LED on the Mini Board is off. At this time, press the WKUP or KEY0 button, you can see the status of the LED flip.

[jump to title](#catalogue)
