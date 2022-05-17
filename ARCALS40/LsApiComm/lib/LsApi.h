//
// ARCA Technologies s.r.l.
// Corso Vercelli, 332 - 10015 Ivrea (TORINO) Italy
//
// Phone ++39 125 235611
// Telefax ++39 125 235623
//
// www.arca.com		techsupp.it@arca.com
//
//
// All rights reserved
//
// We reserve the right to vary technical specification
//
//  MODULE:   LSAPI.H
//
//  PURPOSE:  LS Include Interface


#ifndef LSAPI_H
#define LSAPI_H     1



// ------------------------------------------------------------------------
//                     DEFINES
// ------------------------------------------------------------------------

// Parameter LS Unit Type
#define LS_40_LSCONNECT					39
#define LS_40_USB						40
#define LS_100_USB						100
#define LS_100_RS232					101
#define LS_100_LSCONNECT				109
#define LS_100_ETH						110
#define LS_150_LSCONNECT				149
#define LS_150_USB						150
#define LS_UNIT_SHARED					151
#define LS_200_USB						201
#define LS_5xx_SCSI						500
#define LS_515_LSCONNECT				501
#define LS_515_USB						502
#define LS_520_USB						520
#define LS_800_USB						801

// Old define live for compatibility
#define LS_40_ETH_IPBOX					39
#define LS_100_ETH_IPBOX				109
#define LS_150_ETH_IPBOX				149
#define LS_515_ETH_IPBOX				501


// Parameter FrontStamp
#define NO_STAMP						0
#define FRONT_STAMP						1
#define BACK_STAMP						2
#define FRONT_AND_BACK_STAMP			3


// Parameter Validate
#define NO_PRINT_VALIDATE				0
#define PRINT_VALIDATE					1
#define PRINT_DIGITAL_VALIDATE			2
#define PRINT_LOGO						4
#define PRINT_VALIDATE_WITH_LOGO		5


// Parameter Feed
#define AUTO_FEED						0
#define PATH_FEED						1


// Parameter Sorter
#define HOLD_DOCUMENT					0
#define SORTER_BAY1						1
#define SORTER_BAY2						2
#define SORTER_AUTOMATIC				3
#define SORTER_SWITCH_1_TO_2			4
#define EJECT_DOCUMENT					5
#define SORTER_ON_CODELINE_CALLBACK		6
#define SORTER_ON_CODELINE_CALLBACK_WITH_PRINT	7


// Specific for LS800
#define SORTER_0_SELECTED				0
#define SORTER_1_SELECTED				1
#define SORTER_2_SELECTED				2
#define SORTER_3_SELECTED				3
#define SORTER_4_SELECTED				4
#define SORTER_5_SELECTED				5
#define SORTER_6_SELECTED				6
#define SORTER_7_SELECTED				7
#define SORTER_8_SELECTED				8
#define SORTER_9_SELECTED				9
#define SORTER_10_SELECTED				10
#define SORTER_11_SELECTED				11
#define SORTER_12_SELECTED				12
#define SORTER_13_SELECTED				13
#define SORTER_14_SELECTED				14
#define SORTER_15_SELECTED				15
#define SORTER_16_SELECTED				16
#define SORTER_17_SELECTED				17
#define SORTER_18_SELECTED				18
#define SORTER_19_SELECTED				19
#define SORTER_20_SELECTED				20
#define SORTER_21_SELECTED				21


// Parameter SorterOnChoice
#define SORT_ON_MICR					1
#define SORT_ON_FRONT_IMAGE				2


// Parameter Codeline
#define NO_READ_CODELINE					0
#define READ_CODELINE_MICR					1
#define READ_CODELINE_E13B					4
#define READ_CODELINE_CMC7					5
#define READ_CODELINE_MICR_AND_MICRO_HOLES	6
#define READ_CODELINE_CMC7_MOCR_AND_MICRO_HOLES	7
#define READ_CODELINE_E13B_MICR_WITH_OCR	15
#define READ_CODELINE_CMC7_MICR_WITH_OCR	16
#define READ_CODELINE_OPTIC					21		// LS100 only
#define READ_MICR_AND_OPTIC					22		// LS100 only

#define NO_READ_BARCODE						0
#define READ_BARCODE_2_OF_5					50
#define READ_BARCODE_CODE39					51
#define READ_BARCODE_CODE128				52
#define READ_BARCODE_EAN13					53
#define READ_BARCODE_UCCEAN128				54

#define READ_2D_BARCODE_PDF417				60
#define READ_2D_BARCODE_DATAMATRIX			61
#define READ_2D_BARCODE_QRCODE				62

#define READ_BARCODE_PDF417					2		// Obsolete define, don't use in new application

#define READ_CODELINE_SW_OCRA				0x41	//'A'
#define READ_CODELINE_SW_OCRB_NUM			0x42	//'B'
#define READ_CODELINE_SW_OCRB_ALFANUM		0x43	//'C'
#define READ_CODELINE_SW_OCRB_ITALY			0x46	//'F'
#define READ_CODELINE_SW_OCRB_ARABIC		0x47	//'G'
#define READ_CODELINE_SW_OCRB_PORTUGAL		0x44	//'D'
#define READ_CODELINE_SW_E13B				0x45	//'E'
#define READ_CODELINE_SW_E13B_X_OCRB		0x58	//'X'
#define READ_CODELINE_SW_CMC7				0x48	//'H'
#define READ_CODELINE_MICRO_HOLES			0x4d	//'M'

#define READ_ONE_CODELINE_TYPE				0x4e	//'N'

// Define for OCR expansion Ls150
#define EXP_OCR_CODELINE_E13B_MICR_WITH_OCR		0x0115	// MICR + OCR

#define EXP_OCR_CODELINE_OCRA					0x0141	//'A'
#define EXP_OCR_CODELINE_OCRB_NUM				0x0142	//'B'
#define EXP_OCR_CODELINE_OCRB_ALFANUM			0x0143	//'C'
#define EXP_OCR_CODELINE_E13B_OCR				0x0145	//'E'
#define EXP_OCR_CODELINE_OCRB_ITALY				0x0146	//'F'
#define EXP_OCR_CODELINE_E13B_X_OCRB			0x0158	//'X'

#define EXP_OCR_CODELINE_MICR_AND_OCRA			0x0341	//'A'
#define EXP_OCR_CODELINE_MICR_AND_OCRB_NUM		0x0342	//'B'
#define EXP_OCR_CODELINE_MICR_AND_OCRB_ALFANUM	0x0343	//'C'
#define EXP_OCR_CODELINE_MICR_AND_E13B_OCR		0x0345	//'E'
#define EXP_OCR_CODELINE_MICR_AND_OCRB_ITALY	0x0346	//'F'
#define EXP_OCR_CODELINE_MICR_AND_E13B_X_OCRB	0x0358	//'X'

// NOT USED opzolete
#define READ_CODELINE_HW_OCRA			0x41	//'A'
#define READ_CODELINE_HW_OCRB_NUM		0x42	//'B'
#define READ_CODELINE_HW_OCRB_ALFANUM	0x43	//'C'
#define READ_CODELINE_HW_E13B			0x45	//'E'
#define READ_CODELINE_HW_OCRB_ITALY		0x46	//'F'
#define READ_CODELINE_HW_E13B_X_OCRB	0x58	//'X'


// Parameter encodeBase
#define ENCODE_NO						0
#define ENCODE_BASE_64					64


// Parameter OriginMeasureDoc
#define BOTTOM_LEFT_PIXEL				0
#define BOTTOM_RIGHT_MM					10
#define BOTTOM_RIGHT_INCH				20

#define ORIGIN_DECODE_BOTTOM_LEFT		0
#define ORIGIN_DECODE_BOTTOM_RIGHT		1
#define ORIGIN_DECODE_TOP_RIGHT			2
#define ORIGIN_DECODE_TOP_LEFT			3


// Parameter Unit
#define UNIT_MM							0
#define UNIT_INCH						1


// Value of height to decode a software Codeline
#define MAX_PIXEL_HEIGHT				42
#define OCR_VALUE_IN_MM					10.5
#define OCR_VALUE_IN_INCH				0.41


// Parameter OCR_Image_Side
#define OCR_FRONT_IMAGE					0
#define OCR_BACK_IMAGE					1


// Parameter ResetType
#define RESET_ERROR						0x30
#define RESET_FREE_PATH					0x31
#define RESET_BELT_CLEANING				0x32
#define RESET_COUNTER_CARTRIDGE			0x33
#define RESET_RESERVED					0x34
#define RESET_USB_HW_ERROR				0x39
#define RESET_FREE_PATH_IN_FEEDER		0x51
#define RESET_UNIT_RESERVE				0x60


// Parameter ScanMode
#define SCAN_MODE_BW					1
#define SCAN_MODE_16GR100				2
#define SCAN_MODE_16GR200				3
#define SCAN_MODE_256GR100				4
#define SCAN_MODE_256GR200				5
#define SCAN_MODE_256GR100BN			8
#define SCAN_MODE_256GR200BN			9
#define SCAN_MODE_COLOR_100				10
#define SCAN_MODE_COLOR_200				11
#define SCAN_MODE_COLOR_AND_RED_100		12
#define SCAN_MODE_COLOR_AND_RED_200		13
#define SCAN_MODE_16GR300				20
#define SCAN_MODE_256GR300				21
#define SCAN_MODE_COLOR_300				22
#define SCAN_MODE_256GR300BN			23
#define SCAN_MODE_COLOR_AND_RED_300		24
#define SCAN_MODE_16GR240				30
#define SCAN_MODE_256GR240				31
#define SCAN_MODE_16GR120				34
#define SCAN_MODE_256GR120				35
#define SCAN_MODE_256GR100_AND_UV		40
#define SCAN_MODE_256GR200_AND_UV		41
#define SCAN_MODE_256GR300_AND_UV		42
#define SCAN_MODE_COLOR_100_AND_UV		44
#define SCAN_MODE_COLOR_200_AND_UV		45
#define SCAN_MODE_COLOR_300_AND_UV		46
#define SCAN_MODE_256GR100_ONLY_RED		14
#define SCAN_MODE_256GR200_ONLY_RED		15
#define SCAN_MODE_256GR300_ONLY_RED		16
#define SCAN_MODE_256GR100_ONLY_GREEN	60
#define SCAN_MODE_256GR200_ONLY_GREEN	61
#define SCAN_MODE_256GR300_ONLY_GREEN	62
#define SCAN_MODE_256GR100_ONLY_BLUE	63
#define SCAN_MODE_256GR200_ONLY_BLUE	64
#define SCAN_MODE_256GR300_ONLY_BLUE	65

#define SCAN_MODE_RED_COLOR_100			14	// old define
#define SCAN_MODE_RED_COLOR_200			15	// old define
#define SCAN_MODE_RED_COLOR_300			16	// old define


// Parameter ScanDocType
#define SCAN_PAPER_DOCUMENT				0
#define SCAN_CARD						1
#define SCAN_SHORT_DOCUMENT				2	// Enable the process of short doc. for LS40 ID
#define SCAN_LONG_DOCUMENT				3	// Receipt, Sales Check
#define SCAN_A4_DOCUMENT				4	// Enable scanning Doc A4


// Parameter UVImageType
#define UV_IMAGE_NORMAL					0
#define UV_IMAGE_REVERSE				1


// Parameter ReadMode
#define READMODE_BRUTTO					0
#define READMODE_NETTO					1
#define READMODE_ALL					2


// Parameter ClearBlack
#define NO_CLEAR_BLACK					0
#define CLEAR_ALL_BLACK 				1
#define CLEAR_AND_ALIGN_IMAGE			2

// Parameter Threshold
#define DEFAULT_BLACK_THRESHOLD			0x44


// Parameter UnitSpeed
#define SPEED_DEFAULT					0
#define SPEED_NORMAL					1
#define SPEED_STAMP						1


// Parameter Side
#define SIDE_NONE_IMAGE					'N'
#define SIDE_FRONT_IMAGE				'F'
#define SIDE_BACK_IMAGE					'B'
#define SIDE_ALL_IMAGE					'X'
#define SIDE_FRONT_BLUE_IMAGE			'G'
#define SIDE_BACK_BLUE_IMAGE			'C'
#define SIDE_ALL_BLUE_IMAGE				'Y'
#define SIDE_FRONT_GREEN_IMAGE			'H'
#define SIDE_BACK_GREEN_IMAGE			'D'
#define SIDE_ALL_GREEN_IMAGE			'W'
#define SIDE_FRONT_RED_IMAGE			'I'
#define SIDE_BACK_RED_IMAGE				'E'
#define SIDE_ALL_RED_IMAGE				'Z'


// Parameter lenKey
#define KEY_LENGHT_128					128
#define KEY_LENGHT_256					256
#define KEY_LENGHT_512					512

#define LEN_SIGNATURE_KEY				64


// Parameter Image Coordinate
#define IMAGE_MAX_WIDTH					1720
#define IMAGE_MAX_HEIGHT				864


// Parameter Method
#define ALGORITHM_CTS						0x04
#define ALGORITHM_CTS_2						0x05
#define ALGORITHM_CTS_3						0x06
#define ALGORITHM_CTS_TOP_IMAGE				0x07
#define ALGORITHM_CTS_IMAGE_PRO				0x08
#define ALGORITHM_CTS_CLEAR_PIX				0x09
#define ALGORITHM_NODITHERING				0x10
#define ALGORITHM_FLOYDSTEINDITHERING		0x11
#define ALGORITHM_STUCKIDITHERING			0x12
#define ALGORITHM_BURKESDITHERING			0x13
#define ALGORITHM_SIERRADITHERING			0x14
#define ALGORITHM_STEVENSONARCEDITHERING	0x15
#define ALGORITHM_JARVISDITHERING			0x16

#define DEFAULT_POLO_FILTER					450
#define DEFAULT_CTS_3_THREASHOLD			8


// Parameter Format for LSLoadString
#define PRINT_FORMAT_NORMAL				'N'
#define PRINT_FORMAT_BOLD				'B'
#define PRINT_FORMAT_NORMAL_15_CHAR		'A'
#define PRINT_FORMAT_DOUBLE_HIGH		'D'

#define PRINT_UP_FORMAT_NORMAL			'n'
#define PRINT_UP_FORMAT_BOLD			'b'
#define PRINT_UP_FORMAT_NORMAL_15_CHAR	'a'

// Old define live for compatibility
#define FORMAT_NORMAL					'N'
#define FORMAT_BOLD						'B'
#define FORMAT_NORMAL_15				'A'
#define PRINT_FORMAT_NORMAL_15			'A'


// Parameter Format for LSReadBadge
#define FORMAT_IATA						0x20	// Badge Track 1
#define FORMAT_ABA						0x40	// Badge Track 2
#define FORMAT_MINTS					0x80	// Badge Track 3
#define FORMAT_IATA_ABA					0x60	// Badge Track 1 and 2
#define FORMAT_ABA_MINTS				0xc0	// Badge Track 2 and 3
#define FORMAT_IATA_ABA_MINTS			0xe0	// Badge Track 1, 2 and 3


// Parameter Timeout
#define MIN_TIMEOUT						500


// Parameter Wait_com
#define WAIT_NO							'G'
#define WAIT_YES						'W'


// Parameter Beep
#define	NO_BEEP							0
#define	BEEP							1


// Parameter Message
#define UNIT_MESSAGE_READ				0
#define UNIT_MESSAGE_WRITE				1
#define UNIT_MESSAGE_SHOW				2
#define UNIT_MESSAGE_SHOW_AND_FIX		0x82
#define UNIT_MESSAGE_UNFIX				3
#define UNIT_MESSAGE_PRESENT			4


// Parameter LEDcolor
#define LED_COLOR_DEFAULT				0
#define LED_COLOR_GREEN					1
#define LED_COLOR_RED					2
#define LED_COLOR_AMBER					4


// Parameter Blink
#define BLINK_NO						0
#define BLINK_YES						1


// Parameter CompressionPlace
#define COMPRESSION_ON_PC				0
#define COMPRESSION_ON_LSCONNECT		1


// Parameter DpiImagesJPEG
#define LS_COMPRESSION_TIFF_JPEG		0x8000


// Parameter DpiImagesJPEG, DpiImagesTIFF, DpiImagesBMP
#define IMAGES_RESOLUTION_100_DPI		100
#define IMAGES_RESOLUTION_200_DPI		200
#define IMAGES_RESOLUTION_300_DPI		300


// Parameter TypeImageUV
#define IMAGEUV_NO						0
#define IMAGEUV_BMP_GRAY_100			1
#define IMAGEUV_BMP_GRAY_200			2
#define IMAGEUV_BMP_GRAY_300			3
#define IMAGEUV_BMP_BW_100				4
#define IMAGEUV_BMP_BW_200				5
#define IMAGEUV_BMP_BW_300				6
#define IMAGEUV_BMP_BW_REVERSE_100		7
#define IMAGEUV_BMP_BW_REVERSE_200		8
#define IMAGEUV_BMP_BW_REVERSE_300		9
#define IMAGEUV_JPEG_100				10
#define IMAGEUV_JPEG_200				11
#define IMAGEUV_JPEG_300				12
#define IMAGEUV_CCITTGR4_100			13
#define IMAGEUV_CCITTGR4_200			14
#define IMAGEUV_CCITTGR4_300			15
#define IMAGEUV_CCITTGR4_REVERSE_100	16
#define IMAGEUV_CCITTGR4_REVERSE_200	17
#define IMAGEUV_CCITTGR4_REVERSE_300	18


// Parameter SaveMode
#define	IMAGE_SAVE_ON_FILE				4
#define	IMAGE_SAVE_HANDLE				5
#define	IMAGE_SAVE_BOTH					6
#define	IMAGE_SAVE_NONE					7


// Parameter FileFormat
#define	SAVE_JPEG						10
#define	SAVE_BMP						11
#define FILE_PNG						75


// Parameter: Tiff type
#define FILE_TIF						3		// Tagged Image File Format
#define SAVE_TIF_JPEG					8		// Tagged Image File Format with JPEG compression
#define FILE_CCITT						25		// TIFF  CCITT
#define FILE_CCITT_GROUP3_1DIM			27		// CCITT Group3 one dimension
#define FILE_CCITT_GROUP3_2DIM			28		// CCITT Group3 two dimensions
#define FILE_CCITT_GROUP4				29		// CCITT Group4 two dimensions


// Parameter: szKey Metadata
#define PDFA_DELETE_METADATA			"DeleteAll"


// Parameter: uSaveMulti
#define SAVE_OVERWRITE					0
#define SAVE_APPEND						1
#define SAVE_REPLACE					2
#define SAVE_INSERT						3


// Printer choise
#define PRINTER_FRONT					0
#define PRINTER_BACK					1


#define	CODE_LINE_LENGTH				256		// Max length of returned codeline

#define MAX_OPTICAL_WINDOWS				5		// Nr. window * 5 bytes per window
#define MAX_CRITERIA					5		// Nr. max of selection criteria
#define MAX_CHAR_CHECK					10		// Nr. max of check char


// Parameter Sorter Criteria only for LS515
#define CRITERIA_NO								0x00
#define CRITERIA_ERROR_IN_CODELINE				0x01
#define CRITERIA_CODELINE_EQUAL_STR1			0x02
#define CRITERIA_CODELINE_DIFF_STR1				0x03
#define CRITERIA_CODELINE_GREAT_STR1			0x04
#define CRITERIA_CODELINE_MIN_STR1				0x05
#define CRITERIA_CODELINE_INTO_STR1_STR2		0x06
#define CRITERIA_CODELINE_OUT_STR1_STR2			0x07
#define CRITERIA_CODELINE_EQUAL_STR1_OR_STR2	0x08
#define CRITERIA_CODELINE_DIFF_STR1_AND_STR2	0x09
#define CRITERIA_CODELINE_NOT_PRESENT			0x0a


// Parameter Double Leafing
#define DOUBLE_LEAFING_WARNING			0
#define DOUBLE_LEAFING_ERROR			1

#define DOUBLE_LEAFING_LEVEL1			1
#define DOUBLE_LEAFING_LEVEL2			2
#define DOUBLE_LEAFING_LEVEL3			3
#define DOUBLE_LEAFING_DEFAULT			4
#define DOUBLE_LEAFING_LEVEL4			5
#define DOUBLE_LEAFING_LEVEL5			6
#define DOUBLE_LEAFING_DISABLE			7

#define DOUBLE_LEAFING_LENGTH_10		1
#define DOUBLE_LEAFING_LENGTH_25		0


// Parameter History
#define CMD_READ_HISTORY				1
#define CMD_ERASE_HISTORY				2


// Parameter Color
#define EXTRACT_IMAGE_BLUE				0
#define EXTRACT_IMAGE_GREEN				1
#define EXTRACT_IMAGE_RED				2


#define PERIPHERAL_LS40_SIZE_MEMORY		36 * 1024	//Total memory of the peripheral
#define PERIPHERAL_LS100_SIZE_MEMORY	36 * 1024	//Total memory of the peripheral
#define PERIPHERAL_LS150_SIZE_MEMORY	36 * 1024	//Total memory of the peripheral
#define PERIPHERAL_LS5xx_SIZE_MEMORY	64 * 1024	//Total memory of the peripheral
#define PERIPHERAL_LS800_SIZE_MEMORY	24 * 1024	//Total memory of the peripheral


// String for identify the periferal connected
#define MODEL_LS40						"LS40"

#define MODEL_LS100_1					"LS100USB"
#define MODEL_LS100_2					"LS100RS_"
#define MODEL_LS100_3					"LS100/3_"
#define MODEL_LS100_4					"LS100/4_"
#define MODEL_LS100_5					"LS100/5_"
#define MODEL_LS100_7					"LS100/7_"
#define MODEL_LS100_8					"LS100/8_"
#define MODEL_LS100_ETH					"LS100IP"

#define MODEL_LS150					    "LS150"
#define MODEL_LS150_UV				    "LS150_UV"
#define MODEL_LS150_A4				    "LS150_A4"
#define MODEL_LS150_VE				    "LS150-VE"
#define MODEL_LS150_RD				    "LS150-RD"

#define MODEL_LS200_USB					"LS200USB"
#define MODEL_LS200_1					"C.T.S.  LS200/1"
#define MODEL_LS200_2					"C.T.S.  LS200/2"

#define MODEL_LS500						"C.T.S.  LS500"
#define MODEL_LS505						"C.T.S.  LS505"
#define MODEL_LS510S					"C.T.S.  LS510S"
#define MODEL_LS510D					"C.T.S.  LS510D"
#define MODEL_LS515						"C.T.S.  LS515"
#define MODEL_LS515_1					"C.T.S.  LS515/1"
#define MODEL_LS515_2					"C.T.S.  LS515/2"
#define MODEL_LS515_3					"C.T.S.  LS515/3"
#define MODEL_LS515_5					"C.T.S.  LS515/5"
#define MODEL_LS515_6					"C.T.S.  LS515/6"
#define MODEL_LS520						"C.T.S.  LS520"

#define MODEL_LS800_1					"LS8/1"
#define MODEL_LS800_2					"LS8/2"



// ------------------------------------------------------------------------
//                          REPLY-CODE
// ------------------------------------------------------------------------

#define		LS_OKAY								0

// ------------------------------------------------------------------------
//                  ERRORS
// ------------------------------------------------------------------------
#define		LS_SYSTEM_ERROR						-1
#define		LS_USB_ERROR						-2
#define		LS_PERIPHERAL_NOT_FOUND				-3
#define		LS_HARDWARE_ERROR					-4
#define		LS_PERIPHERAL_OFF_ON				-5
#define		LS_RESERVED_ERROR					-6
#define		LS_PAPER_JAM						-7
#define		LS_TARGET_BUSY						-8
#define		LS_INVALID_COMMAND					-9
#define		LS_DATA_LOST						-10
#define		LS_COMMAND_IN_EXECUTION_YET			-11
#define		LS_JPEG_ERROR						-12
#define		LS_COMMAND_SEQUENCE_ERROR			-13
#define		LS_PC_HW_ERROR						-14
#define		LS_IMAGE_OVERWRITE					-15
#define		LS_INVALID_HANDLE					-16
#define		LS_NO_LIBRARY_LOAD					-17
#define		LS_BMP_ERROR						-18
#define		LS_TIFF_ERROR						-19
#define		LS_IMAGE_NO_MORE_AVAILABLE			-20
#define		LS_IMAGE_NO_FILMED					-21
#define		LS_IMAGE_NOT_PRESENT				-22
#define		LS_FUNCTION_NOT_AVAILABLE			-23
#define		LS_DOCUMENT_NOT_SUPPORTED			-24
#define		LS_BARCODE_ERROR					-25
#define		LS_INVALID_LIBRARY					-26
#define		LS_INVALID_IMAGE					-27
#define		LS_INVALID_IMAGE_FORMAT				-28
#define		LS_INVALID_BARCODE_TYPE				-29
#define		LS_OPEN_NOT_DONE					-30
#define		LS_INVALID_TYPE_COMMAND				-31
#define		LS_INVALID_CLEARBLACK				-32
#define		LS_INVALID_SIDE						-33
#define		LS_MISSING_IMAGE					-34
#define		LS_INVALID_TYPE						-35
#define		LS_INVALID_SAVEMODE					-36
#define		LS_INVALID_PAGE_NUMBER				-37
#define		LS_INVALID_NRIMAGE					-38
#define		LS_INVALID_STAMP					-39
#define		LS_INVALID_WAITTIMEOUT				-40
#define		LS_INVALID_VALIDATE					-41
#define		LS_INVALID_CODELINE_TYPE			-42
#define		LS_MISSING_NRIMAGE					-43
#define		LS_INVALID_SCANMODE					-44
#define		LS_INVALID_BEEP						-45
#define		LS_INVALID_FEEDER					-46
#define		LS_INVALID_SORTER					-47
#define		LS_INVALID_BADGE_TRACK				-48
#define		LS_MISSING_FILENAME					-49
#define		LS_INVALID_QUALITY					-50
#define		LS_INVALID_FILEFORMAT				-51
#define		LS_INVALID_COORDINATE				-52
#define		LS_MISSING_HANDLE_VARIABLE			-53
#define		LS_INVALID_POLO_FILTER				-54
#define		LS_INVALID_ORIGIN_MEASURES			-55
#define		LS_INVALID_SIZEH_VALUE				-56
#define		LS_INVALID_FORMAT					-57
#define		LS_STRINGS_TOO_LONGS				-58
#define		LS_READ_IMAGE_FAILED				-59
#define		LS_INVALID_CMD_HISTORY				-60
#define		LS_MISSING_BUFFER_HISTORY			-61
#define		LS_INVALID_ANSWER					-62
#define		LS_OPEN_FILE_ERROR_OR_NOT_FOUND		-63
#define		LS_READ_TIMEOUT_EXPIRED				-64
#define		LS_INVALID_METHOD					-65
#define		LS_CALIBRATION_FAILED				-66
#define		LS_INVALID_SAVEIMAGE				-67
#define		LS_INVALID_UNIT						-68
#define		LS_INVALID_NRWINDOWS				-71
#define		LS_INVALID_VALUE					-72
#define		LS_ILLEGAL_REQUEST					-73
#define		LS_INVALID_NR_CRITERIA				-74
#define		LS_MISSING_CRITERIA_STRUCTURE		-75
#define		LS_INVALID_MOVEMENT					-76
#define		LS_INVALID_DEGREE					-77
#define		LS_R0TATE_ERROR						-78
#define		LS_MICR_VALUE_OUT_OF_RANGE			-79
#define		LS_PERIPHERAL_RESERVED				-80
#define		LS_INVALID_NCHANGE					-81
#define		LS_BRIGHTNESS_ERROR					-82
#define		LS_CONTRAST_ERROR					-83
#define		LS_INVALID_SIDETOPRINT				-84
#define		LS_DOUBLE_LEAFING_ERROR				-85
#define		LS_INVALID_BADGE_TIMEOUT			-86
#define		LS_INVALID_TIMEOUT					-86
#define		LS_INVALID_RESET_TYPE				-87
#define		LS_MISSING_SET_CALLBACK				-88
#define		LS_IMAGE_NOT_200_DPI				-89
#define		LS_DOWNLOAD_ERROR					-90
#define		LS_INVALID_SORT_ON_CHOICE			-91
#define		LS_INVALID_FONT						-92
#define		LS_INVALID_UNIT_SPEED				-93
#define		LS_INVALID_LENGTH					-94
#define		LS_SHORT_PAPER						-95
#define		LS_INVALID_DOC_LENGTH				-96
#define		LS_INVALID_DOCSLONG					-97
#define		LS_IMAGE_NOT_256_COLOR				-98
#define		LS_BATTERY_NOT_CHARGED				-99
#define		LS_INVALID_SCAN_DOC_TYPE			-100
#define		LS_ILLEGAL_SCAN_CARD_SPEED			-101
#define		LS_INVALID_PWM_VALUE				-102
#define		LS_INVALID_KEY_LENGTH				-103
#define		LS_INVALID_PASSWORD					-104
#define		LS_UNIT_LOCKED						-105
#define		LS_INVALID_IMAGEFORMAT				-106
#define		LS_INVALID_THRESHOLD				-107
#define		LS_NO_START_FOR_SORTER_FULL			-108
#define		LS_IPBOX_ADDRESS_NOT_FOUNDED		-109
#define		LS_INVALID_LED_COMMAND				-110
#define		LS_INVALID_COLOR_PARAMETER			-111
#define		LS_RESIZE_ERROR						-112
#define		LS_ENCODEBASE_INVALID				-113
#define		LS_SW_NOT_LICENSED					-114
#define		LS_INVALID_DPI_IMAGE_JPEG			-115
#define		LS_INVALID_DPI_IMAGE_TIFF			-116
#define		LS_INVALID_DPI_IMAGE_BMP			-117
#define		LS_INVALID_COMPRESSION_PLACE		-118
#define		LS_INVALID_LIMIT					-119
#define		LS_INVALID_OPTION					-120
#define		LS_INVALID_PARAMETER				-121
#define		LS_INVALID_UV_IMAGE_TYPE			-122
#define		LS_MISSING_STRUCTURE_PARAMETER		-123
#define		LS_INVALID_BIT_DEPTH				-124
#define		LS_INVALID_LED_COLOR				-125
#define		LS_INK_DETECTOR_KO					-126
#define		LS_INK_DETECTOR_TIMEOUT				-127
#define		LS_INVALID_DIRECTION				-128
#define		LS_PNG_ERROR						-129
#define		LS_FEATURE_NOT_SUPPORTED			-130
#define		LS_FEATURE_NOT_PRESENT				-131
#define		LS_INVALID_RESOLUTION				-132

#define		LS_JAM_AT_MICR_PHOTO				-201
#define		LS_JAM_DOC_TOO_LONG					-202
#define		LS_JAM_AT_SCANNER_PHOTO				-203
#define		LS_NO_US_SENSOR						-210
#define		LS_US_IN_BOOT						-211
#define		LS_DOC_TOO_LONG						-212
#define		LS_NO_USB_CABLE						-213
#define		LS_SORT_AFTER_RETAINED				-214
#define		LS_NOT_ALLIGN						-215
#define		LS_JAM_AFTER_ALIGN					-216
#define		LS_NO_MOREDOC_RETRY					-217
#define		LS_DOC_NOT_EJECTED					-218
#define		LS_MAX_MOTOR_STEP					-219
#define		LS_EJECT_PHOTO_SCANNER_COVERED		-220
#define		LS_EJECT_PHOTO_TRIGGER_COVERED		-221
#define		LS_PHOTO_TRIGGER_STOP_MICR			-222
#define		LS_DOC_TOO_LONG_AFTER_STAMP			-223
#define		LS_PHOTO_TRIGGER_COVERED			-224
#define		LS_BADGE_TOO_SHORT					-225
#define		LS_PHOTO_FEEDER_COVERED				-226
#define		LS_PHOTO_FEEDER_NOT_COVERED			-227
#define		LS_JAM_ALIGN_BACKWARD				-228
#define		LS_JAM_ALIGN_FORWARD				-229
#define		LS_DOC_TOO_LONG_AFTER_RETAINED		-230
#define		LS_MOTORIZED_BOX_NOT_INSTALLED		-231
#define		LS_FILE_INI_ERROR					-232

#define		LS_INVALID_KEY_LENGHT				-401
#define		LS_IMAGE_CORRUPTED					-402
#define		LS_IMAGE_NOT_SIGNED					-403

#define		LS_SCAN_NETTO_IMAGE_NOT_SUPPORTED	-521
#define		LS_256_GRAY_NOT_SUPPORTED			-522
#define		LS_INVALID_PATH						-523
#define		LS_MISSING_CALLBACK_FUNCTION		-526
#define		LS_INVALID_OCR_IMAGE_SIDE			-558
#define		LS_PERIPHERAL_NOT_ANSWER			-599

#define		LS_INVALID_CONNECTION_HANDLE		-1000
#define		LS_INVALID_CONNECT_PERIPHERAL		-1001
#define		LS_PERIPHERAL_NOT_YET_INTEGRATE		-1002
#define		LS_UNKNOW_PERIPHERAL_REPLY			-1003
#define		LS_CODELINE_ALREADY_DEFINED			-1004
#define		LS_INVALID_NUMBER_OF_DOC			-1005

#define		LS_DECODE_FONT_NOT_PRESENT			-1101
#define		LS_DECODE_INVALID_COORDINATE		-1102
#define		LS_DECODE_INVALID_OPTION			-1103
#define		LS_DECODE_INVALID_CODELINE_TYPE		-1104
#define		LS_DECODE_SYSTEM_ERROR				-1105
#define		LS_DECODE_DATA_TRUNC				-1106
#define		LS_DECODE_INVALID_BITMAP			-1107
#define		LS_DECODE_ILLEGAL_USE				-1108

#define		LS_BARCODE_GENERIC_ERROR		    -1201
#define		LS_BARCODE_NOT_DECODABLE			-1202
#define		LS_BARCODE_OPENFILE_ERROR			-1203
#define		LS_BARCODE_READBMP_ERROR		    -1204
#define		LS_BARCODE_MEMORY_ERROR				-1205
#define		LS_BARCODE_START_NOTFOUND			-1206
#define		LS_BARCODE_STOP_NOTFOUND			-1207

#define		LS_PDF_NOT_DECODABLE				-1301
#define		LS_PDF_READBMP_ERROR				-1302
#define		LS_PDF_BITMAP_FORMAT_ERROR			-1303
#define		LS_PDF_MEMORY_ERROR					-1304
#define		LS_PDF_START_NOTFOUND				-1305
#define		LS_PDF_STOP_NOTFOUND				-1306
#define		LS_PDF_LEFTIND_ERROR				-1307
#define		LS_PDF_RIGHTIND_ERROR				-1308
#define		LS_PDF_OPENFILE_ERROR				-1309
#define		LS_PDF_LOCALIZATION_ERROR			-1310
#define		LS_PDF_TOO_MANY_ERROR				-1321

#define		LS_MICR_DECODE_KO					-1401
#define 	LS_MICR_DECODE_INVALID_BITMAP		-1402
#define 	LS_MICR_DECODE_INVALID_DATA			-1403
#define 	LS_MICR_DECODE_INVALID_CODELINE_LEN	-1404
#define 	LS_MICR_DECODE_ILLEGAL_USE			-1406
#define		LS_MICR_DECODE_ILLEGAL_OPTIONS_UNIT	-1420
#define		LS_MICR_DECODE_ILLEGAL_OPTIONS_SPACE -1421
#define		LS_MICR_DECODE_ILLEGAL_OPTIONS_FONT	-1422

#define		LS_MICROHOLE_FONT_NOT_PRESENT		-1509


// ------------------------------------------------------------------------
//                  WARNINGS
// ------------------------------------------------------------------------
#define		LS_FEEDER_EMPTY						1
#define		LS_DATA_TRUNCATED					2
#define		LS_DOC_PRESENT						3
#define		LS_BADGE_TIMEOUT					4
#define		LS_ALREADY_OPEN						5
#define		LS_PERIPHERAL_BUSY					6
#define		LS_DOUBLE_LEAFING_WARNING			7
#define		LS_COMMAND_NOT_ENDED				8
#define		LS_RETRY							9
#define		LS_NO_OTHER_DOCUMENT				10
#define		LS_QUEUE_FULL						11
#define		LS_NO_SENSE							12
#define		LS_NO_MORE_DATA						13
#define		LS_TRY_TO_RESET						14
#define		LS_STRING_TRUNCATED					15
#define		LS_REPLACE_CARTRIDGE				16
#define		LS_COMMAND_NOT_SUPPORTED			19
#define		LS_SORTER1_FULL						35
#define		LS_SORTER2_FULL						36
#define		LS_SORTERS_BOTH_FULL				37
#define		LS_KEEP_DOC_ON_CODELINE_ERROR		39
#define		LS_LOOP_INTERRUPTED					40

#define		LS_SORTER_1_POCKET_1_FULL			51
#define		LS_SORTER_1_POCKET_2_FULL			52
#define		LS_SORTER_1_POCKET_3_FULL			53
#define		LS_SORTER_2_POCKET_1_FULL			54
#define		LS_SORTER_2_POCKET_2_FULL			55
#define		LS_SORTER_2_POCKET_3_FULL			56
#define		LS_SORTER_3_POCKET_1_FULL			57
#define		LS_SORTER_3_POCKET_2_FULL			58
#define		LS_SORTER_3_POCKET_3_FULL			59
#define		LS_SORTER_4_POCKET_1_FULL			60
#define		LS_SORTER_4_POCKET_2_FULL			61
#define		LS_SORTER_4_POCKET_3_FULL			62
#define		LS_SORTER_5_POCKET_1_FULL			63
#define		LS_SORTER_5_POCKET_2_FULL			64
#define		LS_SORTER_5_POCKET_3_FULL			65
#define		LS_SORTER_6_POCKET_1_FULL			66
#define		LS_SORTER_6_POCKET_2_FULL			67
#define		LS_SORTER_6_POCKET_3_FULL			68
#define		LS_SORTER_7_POCKET_1_FULL			69
#define		LS_SORTER_7_POCKET_2_FULL			70
#define		LS_SORTER_7_POCKET_3_FULL			71


// ------------------------------------------------------------------------
//					DEFINES STRUCTURES
// ------------------------------------------------------------------------

typedef struct _UNITCONFIGURATION
{
	int		Size;						// Size of the structure

	BOOL	MICR_Reader;				//	Ls40 Ls100 Ls150 Ls515 Ls800
	BOOL	CMC7_Reader_only;			//		 Ls100 Ls150 Ls515 Ls800
	BOOL	E13B_Reader_only;			//		 Ls100 Ls150 Ls515 Ls800
	BOOL	Scanner_Front;				//		 Ls100 Ls150 Ls515 Ls800
	BOOL	Scanner_Rear;				//		 Ls100 Ls150 Ls515 Ls800
	BOOL	InkJet_Printer;				//		 Ls100 Ls150 Ls515 Ls800
	BOOL	InkJet_HD_Printer_4_lines;	//			   Ls150 Ls515 Ls800
	BOOL	Feeder;						//		 Ls100
	BOOL	Double_Leafing_sensor;		//	Ls40			 Ls515
	BOOL	Voiding_Front_Stamp;		//		 Ls100       Ls515
	BOOL	Voiding_Rear_Stamp;			//					 Ls515
	BOOL	No_Blanks;					//					 Ls515
	BOOL	Badge_Track123;				//		 Ls100 Ls150
	BOOL	Badge_Track12;				//		 Ls100 Ls150 Ls515
	BOOL	Badge_Track23;				//		 Ls100 Ls150 Ls515
	BOOL	OCR_Reader;					//		 Ls100
	int 	Sorters_Nr;					//						   Ls800
	BOOL	Module_Encoder;				//						   Ls800
	BOOL    Process_Card;				//	Ls40
	BOOL    Capacitor;					//	Ls40
	BOOL	Scanner_UltraViolet;		//			   Ls150 Ls515
	BOOL    Scanner_Color;				//			   Ls150
	BOOL    Hight_Speed;				//			   Ls150
	BOOL	Feeder_Motorized;			//			   Ls150
	BOOL	Feeder_Electromagnet;		//			   Ls150
	BOOL	ID_Card_Color;				//			   Ls150
	BOOL	License_ClearPIX;			//	Ls40 Ls100 Ls150 Ls515
	BOOL	License_2D_Barcode;			//	Ls40 Ls100 Ls150 Ls515
	BOOL	License_IQA;				//	Ls40 Ls100 Ls150 Ls515
	BOOL	License_Micro_Hole;			//	Ls40 Ls100 Ls150 Ls515
	BOOL	Ink_Detector;				//		 Ls100
	BOOL    SensorCartridge;			//			   Ls150

} UNITCONFIGURATION, *PUNITCONFIGURATION;


typedef struct _UNITSTATUS
{
	int		Size;						// Size of the structure

	int		UnitStatus;					// Ls40 Ls100 Ls150 Ls5xx Ls800

	BOOL	Photo_Feeder;				// Ls40 Ls100 Ls150 Ls5xx Ls800
	BOOL	Photo_Sorter;				//      Ls100
	BOOL	Photo_MICR;					//      Ls100 Ls150 Ls5xx
	BOOL	Photo_Path_Ls100;			//      Ls100
	BOOL	Photo_Scanners;				//      Ls100
	BOOL	Unit_Just_ON;				// Ls40 Ls100 Ls150
	BOOL	Photo_Double_Leafing_Down;	//      Ls100 Ls150
	BOOL	Photo_Double_Leafing_Middle;//            Ls150
	BOOL	Photo_Double_Leafing_Up;	//      Ls100 Ls150
	BOOL	Photo_Card;					//            Ls150
	BOOL	Pockets_All_Full;			//            Ls150 Ls5xx
	BOOL	Photo_Stamp;				//                  Ls5xx
	BOOL	Photo_Exit;					//                  Ls5xx
	BOOL	Pocket_1_Full;				//                  Ls5xx
	BOOL	Pocket_2_Full;				//                  Ls5xx

	BOOL	Photo_Path_Feeder;			//                        Ls800
	BOOL	Photo_Path_Module_Begin;	//                        Ls800
	BOOL	Photo_Path_Binary_Rigth;	//                        Ls800
	BOOL	Photo_Path_Binary_Left;		//                        Ls800
	BOOL	Photo_Path_Module_End;		//                        Ls800
	BOOL	Sorter_1_input_pocket_1;	//                        Ls800
	BOOL	Sorter_1_pocket_1_full;		//                        Ls800
	BOOL	Sorter_1_input_pocket_2;	//                        Ls800
	BOOL	Sorter_1_pocket_2_full;		//                        Ls800
	BOOL	Sorter_1_input_pocket_3;	//                        Ls800
	BOOL	Sorter_1_pocket_3_full;		//                        Ls800
	BOOL	Sorter_2_input_pocket_1;	//                        Ls800
	BOOL	Sorter_2_pocket_1_full;		//                        Ls800
	BOOL	Sorter_2_input_pocket_2;	//                        Ls800
	BOOL	Sorter_2_pocket_2_full;		//                        Ls800
	BOOL	Sorter_2_input_pocket_3;	//                        Ls800
	BOOL	Sorter_2_pocket_3_full;		//                        Ls800
	BOOL	Sorter_3_input_pocket_1;	//                        Ls800
	BOOL	Sorter_3_pocket_1_full;		//                        Ls800
	BOOL	Sorter_3_input_pocket_2;	//                        Ls800
	BOOL	Sorter_3_pocket_2_full;		//                        Ls800
	BOOL	Sorter_3_input_pocket_3;	//                        Ls800
	BOOL	Sorter_3_pocket_3_full;		//                        Ls800
	BOOL	Sorter_4_input_pocket_1;	//                        Ls800
	BOOL	Sorter_4_pocket_1_full;		//                        Ls800
	BOOL	Sorter_4_input_pocket_2;	//                        Ls800
	BOOL	Sorter_4_pocket_2_full;		//                        Ls800
	BOOL	Sorter_4_input_pocket_3;	//                        Ls800
	BOOL	Sorter_4_pocket_3_full;		//                        Ls800
	BOOL	Sorter_5_input_pocket_1;	//                        Ls800
	BOOL	Sorter_5_pocket_1_full;		//                        Ls800
	BOOL	Sorter_5_input_pocket_2;	//                        Ls800
	BOOL	Sorter_5_pocket_2_full;		//                        Ls800
	BOOL	Sorter_5_input_pocket_3;	//                        Ls800
	BOOL	Sorter_5_pocket_3_full;		//                        Ls800
	BOOL	Sorter_6_input_pocket_1;	//                        Ls800
	BOOL	Sorter_6_pocket_1_full;		//                        Ls800
	BOOL	Sorter_6_input_pocket_2;	//                        Ls800
	BOOL	Sorter_6_pocket_2_full;		//                        Ls800
	BOOL	Sorter_6_input_pocket_3;	//                        Ls800
	BOOL	Sorter_6_pocket_3_full;		//                        Ls800
	BOOL	Sorter_7_input_pocket_1;	//                        Ls800
	BOOL	Sorter_7_pocket_1_full;		//                        Ls800
	BOOL	Sorter_7_input_pocket_2;	//                        Ls800
	BOOL	Sorter_7_pocket_2_full;		//                        Ls800
	BOOL	Sorter_7_input_pocket_3;	//                        Ls800
	BOOL	Sorter_7_pocket_3_full;		//                        Ls800

	BOOL	Photo_Trigger;				// Ls40
	BOOL	Document_Retained;			// Ls40
	BOOL	Photo_Print_Cartridge;		//            Ls150

	BOOL	Photo_MT_DocAlign;			// Ls40
	BOOL	Photo_MT_Pinch;				// Ls40
	BOOL	Photo_MT_Restart;			// Ls40
	BOOL	Photo_MT_US_DocInFeeder;	// Ls40
	BOOL	Photo_MT_US_DL_InFeeder;	// Ls40

} UNITSTATUS, *PUNITSTATUS;


typedef struct _UNITHISTORY
{
	int			Size;						// Size of the structure

	unsigned long	doc_sorted;				// Document sortered
	unsigned long	doc_retained;			// Nr. of document retained
	unsigned long	doc_retained_micr;		// Nr. documents retained after MICR header
	unsigned long	doc_retained_scan;		// Nr. documents retained after front scanning
	unsigned long	doc_ink_jet;			// Nr. of document printed
	unsigned long	doc_stamped;			// Nr. of document stamped

	unsigned long	tot_paper_jams;			// Totally of Paper jam
	unsigned long	jams_in_feeder;			// Nr. jam in the feeder
	unsigned long	jams_in_micr;			// Nr. jam during the MICR reading
	unsigned long	jams_scanner;			// Nr. jam between scanners
	unsigned long	jams_stamp;				// Nr. jam at stamp document
	unsigned long	jams_on_exit;			// Nr. jam after the film
	unsigned long	jams_card;				// Nr. jam in the card entry
	unsigned long	nr_double_leafing;		// Nr. double leafing occurs Ls800 only

	unsigned long	tot_doc_MICR_err;		// Totally MICR document, read with error
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	doc_hw_barcode_err;		// Nr. of document Barcode, read from LS with error
	unsigned long	doc_hw_optic_err;		// Nr. of document OCR, read from LS with error

	unsigned long	num_turn_on;			// Nr. of power ON
	unsigned long	time_peripheral_on;		// Minutes peripheral time life

	// Section specific Ls800 unit
	unsigned long	jam_front_scanner;		// Jam in scanner front
	unsigned long	jam_track_left;			// Jam in the left track
	unsigned long	jam_track_right;		// Jam in the right track
	unsigned long	jam_back_scanner;		// Jam in scanner back
	unsigned long	jam_in_the_sorters;		// Jam in sorters track
	// Section compiled only from Ls800 unit

	unsigned long	nr_drops_printed;		// Nr. drops printed
	unsigned long	first_power_on_day;		// Date of first power ON
	unsigned long	first_power_on_month;	// Date of first power ON
	unsigned long	first_power_on_year;	// Date of first power ON

} UNITHISTORY, *PUNITHISTORY;


// structure for configure the read codeline from bitmap
typedef struct _ReadOption
{
	BOOL	PutBlanks;
	char	TypeRead;
}READOPTIONS, *LPREADOPTIONS;


// Structure for read MicroHole
typedef struct _MicroHoleStruct
{
	float x;
	float y;
	float width;
	float height;
	BOOL  TrueHole;
	char  *strFront;
	short dimStrFront;
	char  *strRear;
	short dimStrRear;
} MICROHOLE_STRUCT, *PMICROHOLE_STRUCT;


typedef struct _DATAOPTICALWINDOW
{
	unsigned char	TypeRead;			// Type of read choise
	unsigned char	Reserved;			// Reserved
	short			XRightBottom;		// X1 coordinates
	short			YRightBottom;		// Y1 coordinates
	short			Size;				// size
	short			Height;				// height
} DATAOPTICALWINDOW, *PDATAOPTICALWINDOW;


typedef struct _DATASORTERSELECT
{
	char	TypeCriteria;				// Type of criteria choise
	char	CharToStart;				// Char to start check in the codeline
	char	NrCharCheck;				// Length string 1 and/or string 2
	char	String1[MAX_CHAR_CHECK];	// String 1
	char	String2[MAX_CHAR_CHECK];	// String 2
	char	Bin;						// Bin where put the document
} DATASORTERSELECT, *PDATASORTERSELECT;


// Structure used for return information about the just read codeline
typedef struct _S_CODELINE_INFO
{
	// Parameter compiled from LS500.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progessive document number
	char			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application
	short			Sorter;							// Sorter where put the document
	char			FormatString;					// Set from application NORMAL or BOLD
	char			StringToPrint[80];				// String to print rear of the document
} S_CODELINE_INFO, *LPS_CODELINE_INFO;


// Structure used for return information about the just read codeline
typedef struct _S_CODELINE_INFO_VB
{
	// Parameter compiled from LS500.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progessive document number
	WCHAR			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application
	short			Sorter;							// Sorter where put the document
	short			FormatString;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint[80];				// String to print rear of the document
} S_CODELINE_INFO_VB, *LPS_CODELINE_INFO_VB;


// structure for read usefull information about the just stored image
typedef struct _S_CODELINE_INFO_LS100
{
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progessive document number
	char			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
} S_CODELINE_INFO_LS100, *LPS_CODELINE_INFO_LS100;


// structure for read usefull information about the just stored image
typedef struct _S_IMAGE_INFO_LS100
{
	short			Size;				// Size of the struct
	unsigned long	NrDoc;				// Progressive document number
	HANDLE			hImage;				// Image handle
	int				ImageSize;			// Image size bytes
	int				Width;				// Image width
	int				Height;				// Image height
	int				Resolution;			// Image resolution
	int				BitCount;			// Image bit count (level of grey)
} S_IMAGE_INFO_LS100, *LPS_IMAGE_INFO_LS100;


// Structure used for return information about the just read codeline
typedef struct _S_CODELINE_INFO_LS800
{
	// Parameter compiled from LS800.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progessive document number
	char			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application
	short			Sorter;							// Sorter where put the document
	char			FormatString1;					// Set from application NORMAL or BOLD
	char			StringToPrint1[80];				// String line 1 to print rear of the document
	char			FormatString2;					// Set from application NORMAL or BOLD
	char			StringToPrint2[80];				// String line 2 to print rear of the document
	char			FormatString3;					// Set from application NORMAL or BOLD
	char			StringToPrint3[80];				// String line 3 to print rear of the document
	char			FormatString4;					// Set from application NORMAL or BOLD
	char			StringToPrint4[80];				// String line 4 to print rear of the document
} S_CODELINE_INFO_LS800, *LPS_CODELINE_INFO_LS800;


// Structure used for return information about the just film image
typedef struct _S_IMAGE_INFO_LS800
{
	// Parameter compiled from LS800.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progressive document number
	HANDLE			hImage;							// Image handle
	int				ImageSize;						// Image size bytes
	int				Width;							// Image width
	int				Height;							// Image height
	int				Resolution;						// Image resolution
	int				BitCount;						// Image bit count (level of grey)
	char			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application (only for image front)
	short			Sorter;							// Sorter where put the document
	char			FormatString1;					// Set from application NORMAL or BOLD
	char			StringToPrint1[80];				// String line 1 to print rear of the document
	char			FormatString2;					// Set from application NORMAL or BOLD
	char			StringToPrint2[80];				// String line 2 to print rear of the document
	char			FormatString3;					// Set from application NORMAL or BOLD
	char			StringToPrint3[80];				// String line 3 to print rear of the document
	char			FormatString4;					// Set from application NORMAL or BOLD
	char			StringToPrint4[80];				// String line 4 to print rear of the document
} S_IMAGE_INFO_LS800, *LPS_IMAGE_INFO_LS800;


// Structure used for return information about the just read codeline
typedef struct _S_CODELINE_INFO_VB_LS800
{
	// Parameter compiled from LS800.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progessive document number
	WCHAR			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application
	short			Sorter;							// Sorter where put the document
	short			FormatString1;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint1[80];				// String line 1 to print rear of the document
	short			FormatString2;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint2[80];				// String line 2 to print rear of the document
	short			FormatString3;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint3[80];				// String line 3 to print rear of the document
	short			FormatString4;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint4[80];				// String line 4 to print rear of the document
} S_CODELINE_INFO_VB_LS800, *LPS_CODELINE_INFO_VB_LS800;


// Structure used for return information about the just film image
typedef struct _S_IMAGE_INFO_VB_LS800
{
	// Parameter compiled from LS800.dll
	short			Size;							// Size of the struct
	unsigned long	NrDoc;							// Progressive document number
	HANDLE			hImage;							// Image handle
	int				ImageSize;						// Image size bytes
	int				Width;							// Image width
	int				Height;							// Image height
	int				Resolution;						// Image resolution
	int				BitCount;						// Image bit count (level of grey)
	WCHAR			CodelineRead[CODE_LINE_LENGTH];	// Codeline returned
	short			NrBytes;						// Length of the codeline
	unsigned long	Reserved;						// Reserved for future use

	// Parameter compiled from Application (only for image front)
	short			Sorter;							// Sorter where put the document
	short			FormatString1;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint1[80];				// String line 1 to print rear of the document
	short			FormatString2;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint2[80];				// String line 2 to print rear of the document
	short			FormatString3;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint3[80];				// String line 3 to print rear of the document
	short			FormatString4;					// Set from application NORMAL or BOLD
	WCHAR			StringToPrint4[80];				// String line 4 to print rear of the document
} S_IMAGE_INFO_VB_LS800, *LPS_IMAGE_INFO_VB_LS800;





// structure for read usefull information about peripheral life LS40
typedef struct _HistoryLs40
{
	short			Size;					// Size of the struct
	unsigned long	doc_sorted;				// Document sortered
	unsigned long	doc_ink_jet;			// Nr. of document printed
	unsigned long	doc_stamp;				// Nr. of document stamped
	unsigned long	doc_retain;				// Nr. of document retained
	unsigned long	paper_jam;				// Nr. of Paper jam
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	num_turn_on;			// Nr. of power on
	unsigned long	time_peripheral_on;		// Minutes peripheral time life

} S_HISTORY_LS40, *LPS_HISTORY_LS40;


// structure for read usefull information about peripheral life LS100
typedef struct _HistoryLs100
{
	short			Size;					// Size of the struct
	unsigned long	doc_sorted;				// Document sortered
	unsigned long	bourrage_feeder;		// Jam in the feeder
	unsigned long	bourrage_micr;			// Jam during the MICR reading
	unsigned long	doc_retain;				// Nr. of document retained
	unsigned long	bourrage_exit;			// Jam after the film
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	time_peripheral_on;		// Minutes peripheral time life
	unsigned long	num_turn_on;			// Nr. of power on
	unsigned long	doc_ink_jet;			// Nr. of document printed
	unsigned long	doc_stamp;				// Nr. of document stamped

} S_HISTORY_LS100, *LPS_HISTORY_LS100;


// structure for read usefull information about peripheral life LS150
typedef struct _HistoryLs150
{
	short			Size;					// Size of the struct
	unsigned long	doc_sorted;				// Nr. of document sortered
	unsigned long	doc_retain;				// Nr. of document retained
	unsigned long	jams_card;				// Jam in the card entry
	unsigned long	jams_micr;				// Jam during the MICR reading
	unsigned long	jams_scanner;			// Jam in the feeder
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	time_peripheral_on;		// Minutes peripheral time life
	unsigned long	num_turn_on;			// Nr. of power on
	unsigned long	doc_ink_jet;			// Nr. of document printed
	unsigned long	doc_stamp;				// Nr. of document stamped
	unsigned long	nr_drops_printed;		// Nr. of drops printed
	unsigned long	date_first_turn_on;		// Date first power ON

} S_HISTORY_LS150, *LPS_HISTORY_LS150;


// structure for read usefull information about peripheral life LS200
typedef struct _HistoryLs200
{
	short			Size;					// Size of the struct
	unsigned long	nrDocProcessed;			// Document sortered
	unsigned long	nrJamFeeder;			// Jam in the feeder
	unsigned long	nrJamPath;				// Jam in the path
	unsigned long	nrJamBin;				// Jam in the pockets
	unsigned long	nrDocPrint;				// Nr. of document printed
	unsigned long	nrDocStamp;				// Nr. of document stamped
	unsigned long	nrDoubleLeafing;		// Nr. of double leafing occurs
	unsigned long	nrErrMICR;				// Nr. of document MICR, read with error
	unsigned long	nrErrOptic;				// Nr. of document Optic, read with error
	unsigned long	nrErrBarcode;			// Nr. of document Barcode, read with error
	unsigned long	time_peripheral_on;		// Seconds peripheral time life

} S_HISTORY_LS200, *LPS_HISTORY_LS200;


// structure for read usefull information about peripheral life LS5xx
typedef struct _HistoryLs5xx
{
	short			Size;					// Size of the struct
	unsigned long	num_doc_handled;		// Nr. documents handled
	unsigned long	bourrage_feeder;		// Nr. jam in the feeder
	unsigned long	doc_retain_micr;		// Nr. documents retained after MICR header
	unsigned long	doc_retain_scan;		// Nr. documents retained after front scanning
	unsigned long	bourrage_stamp;			// Nr. jam at stamp document
	unsigned long	bourrage_film;			// Nr. jam during scan document
	unsigned long	bourrage_micr;			// Nr. jam during read MICR document
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	doc_barcode_err;		// Nr. of document Barcode, read with error
	unsigned long	doc_optic_err;			// Nr. of document OCR, read with error
	unsigned long	time_peripheral_on;		// Seconds peripheral time life
	unsigned long	nr_power_on;			// Nr. of time power ON
	unsigned long	nr_drops_printed;		// Nr. of drops printed

} S_HISTORY_LS5xx, *LPS_HISTORY_LS5xx;


// structure for read usefull information about the peripheral life LS800
typedef struct _HistoryLs800
{
	short			Size;					// Size of the struct
	unsigned long	num_doc_handled;		// Nr. documents handled
	unsigned long	jam_feeder;				// Nr. jam in the feeder
	unsigned long	jam_front_scanner;		// Jam in scanner front
	unsigned long	jam_track_left;			// Jam in the left track
	unsigned long	jam_track_right;		// Jam in the right track
	unsigned long	jam_back_scanner;		// Jam in scanner back
	unsigned long	jam_in_the_sorters;		// Jam in sorters track
	unsigned long	doc_cmc7_err;			// Nr. of document CMC7, read with error
	unsigned long	doc_e13b_err;			// Nr. of document E13B, read with error
	unsigned long	doc_printed;			// Nr. of documents printed
	unsigned long	time_peripheral_on;		// Seconds peripheral time life
	unsigned long	nr_power_on;			// Nr. of time power ON
	unsigned long	nr_double_leafing;		// Nr. double leafing occurs

} S_HISTORY_LS800, *LPS_HISTORY_LS800;




// ------------------------------------------------------------------------
//                  EXPORT FUNCTIONS
// ------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern int APIENTRY LSConnect(HWND		hWnd,
							  HANDLE	hInst,
							  short		LsUnitType,
							  short		*hConnect);

extern int APIENTRY LSConnectWithTmpPath(HWND	hWnd,
										 HANDLE	hInstAppl,
										 short	LsUnitType,
										 short	*hConnect,
										 char	*PathTemp);

extern int APIENTRY LSUnitReserve(short	hConnect,
								  HWND	hWnd,
								  long	Timeout);

extern int APIENTRY LSUnitRelease(short hConnect,
								  HWND	hWnd);

extern int APIENTRY LSSetNetworkName(short			LsUnitType,
									 char			*New_Network_Node_Name,
									 unsigned short New_Net_Port);

extern int APIENTRY LSConnectWithNetworkName(HWND			hWnd,
											 HANDLE			hInstAppl,
											 short			LsUnit,
											 char			*IpBoxName,
											 unsigned short	NetPort,
											 short			*hConnect);

extern int APIENTRY LSSetIPAddress(short		  LsUnitType,
								   char			 *New_Eth_IpAddress,
								   unsigned short New_Net_Port);

extern int APIENTRY LSConnectWithIPAddress(HWND			  hWnd,
										   HANDLE		  hInstAppl,
										   short		  LsUnitType,
										   char			 *IpAddress,
										   unsigned short NetPort,
										   short		 *hConnect);

extern int APIENTRY LSDisconnect(short	hConnect,
								 HWND	hWnd);

extern int APIENTRY LSRS232Configuration(short		LsUnitType,
										 HWND		hWnd,
										 char		*Porta,
										 DWORD		BaudeRate,
										 short		Parity,
										 short		ByteSize,
										 short		BitsStop);

extern int APIENTRY LSUnitConfiguration(short		hConnect,
										HWND		hWnd,
										LPSTR		lpReserved,
										UNITCONFIGURATION	*DeviceFeatures,
										LPSTR		LsModel,
										LPSTR		Fw_Version,
										LPSTR		Fw_Date,
										LPSTR		PeripheralID,
										LPSTR		BoardAndFPGANr,
										LPSTR		ExpVersion,
										LPSTR		InkJetVersion,
										LPSTR		FeederVersion,
										LPSTR		SorterVersion,
										LPSTR		MotorVersion,
										LPSTR		LsApiEthVersion,
										LPSTR		Reserved2);

extern int APIENTRY LSUnitHistory(short			hConnect,
								  HWND			hWnd,
								  UNITHISTORY	*sHistory);

extern int APIENTRY LSUnitStatus(short		hConnect,
								 HWND		hWnd,
								 UNITSTATUS	*lpStatus);

extern int APIENTRY LSConfigDoubleLeafingAndDocLength(short	hConnect,
													  HWND	hWnd,
													  long	Type,
													  short	Value,
													  long	DocMin,
													  long	DocMax);

extern int APIENTRY LSConfigDoubleLeafingAndDocLengthEx(short	hConnect,
														HWND	hWnd,
														long	Type,
														short	Value,
														long	DocMin,
														long	DocMax,
														long	DocMinAccepted);

extern int APIENTRY LSSetLightIntensity(short	hConnect,
										HWND	hWnd,
										short	Value);

extern int APIENTRY LSDocHandle(short			hConnect,
								HWND			hWnd,
								short			Stamp,
								short			Validate,
								short			CodeLine,
								char			Side,
								short			ScanMode,
								short			Feeder,
								short			Sorter,
								short			WaitTimeout,
								short			Beep,
								unsigned long	*NrDoc,
								short			ScanDocType,
								LPVOID			Reserved2);

extern int APIENTRY LSDocHandleAndReadImage(short	hConnect,
											HWND	hWnd,
											short	Stamp,
											short	Validate,
											short	CodeLine,
											char	Side,
											short	ScanMode,
											short	Feeder,
											short	Sorter,
											short	WaitTimeout,
											short	Beep,
											short	ScanDocType,
											long	Reserved2,
											short		ClearBlack,
											LPHANDLE	FrontImage,
											LPHANDLE	BackImage,
											LPHANDLE	FrontImage2,
											LPHANDLE	BackImage2);

extern int APIENTRY LSSetSorterCriteria(short			hConnect,
										HWND			hWnd,
										DATASORTERSELECT *pCriteria,
										short			NrCriteria);

extern int APIENTRY LSReadImage(short			hConnect,
								HWND			hWnd,
								short			ClearBlack,
								char			Side,
								short			ReadMode,
								unsigned long	NrDoc,
								LPHANDLE		FrontImage,
								LPHANDLE		BackImage,
								LPHANDLE		Reserved1,
								LPHANDLE		Reserved2);

extern int APIENTRY LSReadImageEx(short			hConnect,
								  HWND			hWnd,
								  short			ClearBlack,
								  char			Side,
								  int			ImageFormat,
								  short			Quality,
								  short			Method,
								  short			Threshold,
								  unsigned long	NrDoc,
								  LPHANDLE		FrontImage,
								  int			*SizeFront,
								  LPHANDLE		RearImage,
								  int			*SizeRear,
								  LPHANDLE		FrontImage2,
								  int			*SizeFront2,
								  LPHANDLE		RearImage2,
								  int			*SizeRear2);

extern int APIENTRY LSReadImageMH(short			hConnect,
								  HWND			hWnd,
								  short			ClearBlack,
								  char			Side,
								  short			ReadMode,
								  unsigned long	NrDoc,
								  LPHANDLE		FrontImage,
								  LPHANDLE		BackImage,
								  LPHANDLE		FrontImage2,
								  LPHANDLE		BackImage2,
								  BOOL			VerifyHole,
								  short			Unit,
								  short			nrRegions,
								  MICROHOLE_STRUCT	*stMicroHole);

extern int APIENTRY LSSetThresholdClearBlack(short			hConnect,
											 HWND			hWnd,
											 unsigned char	Threshold);

extern int APIENTRY LSEnableImageCorrection(short	hConnect,
											HWND	hWnd,
											BOOL	fDo);

extern int APIENTRY LSReadImagePiece(short			hConnect,
									 HWND			Hwnd,
									 char			Side,
									 unsigned long	NrDoc,
									 int			pos_x,
									 int			pos_y,
									 int			sizeW,
									 int			sizeH,
									 LPHANDLE		hImage);

extern int APIENTRY LSSaveJPEG(HWND		hWnd, 
							   HANDLE	hImage, 
							   int		quality, 
							   LPSTR	filename);

extern int APIENTRY LSSaveDIB(HWND		hWnd,
							  HANDLE	hImage,
							  LPSTR		filename);

extern int APIENTRY LSSaveTIFFEx(HWND	hWnd,
								 HANDLE	hImage,
								 LPSTR	filename,
								 int	Type,
								 int	quality,
								 int	SaveMode,
								 int	PageNumber);

extern int APIENTRY LSSavePNG(HWND		hWnd,
							  HANDLE	hImage,
							  int		quality,
							  int		SaveMode,
							  int		PageNumber,
							  LPSTR		filename);

extern int APIENTRY LSConvertToTIFF(HWND	hWnd,
									HANDLE	hImage,
									int		Type,
									int		Quality,
									int		SaveMode,
									int		PageNumber,
									HANDLE	*TiffImage,
									long	*ImageSize);

extern int APIENTRY LSConvertToJPEG(HWND	hWnd,
									HANDLE	hImage,
									int		quality,
									HANDLE	*JpegImage,
									long	*ImageSize);

extern int APIENTRY LSConvertToPNG(HWND		hWnd,
								   HANDLE	hImage,
								   int		Quality,
								   int		SaveMode,
								   int		PageNumber,
								   HANDLE	*PngImage,
								   long		*ImageSize);

extern int APIENTRY LSRotateImageEx(HWND	hWnd,
									HANDLE	hImage,
									int		degree,
									HANDLE	*pImage);

extern int APIENTRY LSImageBrightness(HWND		hWnd,
									  HANDLE	hImage,
									  int		nChange,
									  HANDLE	*pImage);

extern int APIENTRY LSImageContrast(HWND	hWnd,
									HANDLE	hImage,
									int		nChange,
									HANDLE *pImage);

extern int APIENTRY LSCutImage(HWND		hWnd,
							   HANDLE	hImage,
							   short	Unit,
							   float	pos_x,
							   float	pos_y,
							   float	sizeW,
							   float	sizeH,
							   HANDLE	*pImage);

extern int APIENTRY LSGetImageLengthInMM(HWND	hWnd,
										 HANDLE hImage,
										 int	*lenImage);

extern int APIENTRY LSSetOpticalWindows(short	hConnect,
										HWND	hWnd,
										PDATAOPTICALWINDOW pDimWindows,
										short	NrWindows);

extern int APIENTRY LSReadCodeline(short	hConnect,
								   HWND		hWnd,
								   LPSTR	Codeline,
								   short	*Length_Codeline,
								   LPSTR	Barcode,
								   short	*Length_Barcode,
								   LPSTR	Optic,
								   short	*Length_Optic);

extern int APIENTRY LSReadCodelineFromBitmap(HWND		hWnd,
											 HANDLE		hImage,
											 char		*codelineType,
											 int		x,
											 int		y,
											 int		sizeW,
											 int		sizeH,
											 READOPTIONS *Option,
											 LPSTR		Codeline,
											 UINT		*Length);

extern int APIENTRY LSCodelineReadFromBitmap(HWND		hWnd,
											 HANDLE		hImage,
											 char		*codelineType,
											 short		UnitMeasure,
											 float		x,
											 float		y,
											 float		sizeW,
											 float		sizeH,
											 READOPTIONS *Option,
											 LPSTR		Codeline,
											 UINT		*Length);

extern int APIENTRY LSReadMicroHolesCodelines(HWND		hWnd,
											  HANDLE	hImageFront,
											  HANDLE	hImageRear,
											  BOOL		VerifyHole,
											  short		Unit,
											  short		nrRegions,
											  MICROHOLE_STRUCT	*stMicroHole);

extern int APIENTRY LSReadBarcodesDriverLicense(HWND	hWnd,
												HANDLE	hImage,
												short	encodeBase,
												LPSTR	Codeline_2D,
												int		*Length_2D,
												short	*ErrorRate,
												int		TypeBarcode_1D,
												LPSTR	Codeline_1D,
												int		*Length_1D,
												int		Reserved1,
												int		Reserved2,
												int		Reserved3,
												int		Reserved4);

extern int APIENTRY LSReadBarcodeFromBitmap(HWND	hWnd,
											HANDLE	hImage,
											char	TypeBarcode,
											int		pos_x,
											int		pos_y,
											int		sizeW,
											int		sizeH,
											LPSTR	Codeline,
											UINT	*Length);

extern int APIENTRY LSGetNextBarcode(HWND	hWnd,
									 LPSTR	Codeline,
									 long	*Length);

extern int APIENTRY LSSetBinarizationParameters(short	hConnect,
												HWND	hWnd,
												short	Method,
												short	Threshold,
												float	Margine);

extern int APIENTRY LSSetPoloFilterForScanModeBW(short hConnect,
												 HWND  hWnd,
												 short PoloFilter,
												 float Reserved);

extern int APIENTRY LSConvertImageToBW(HWND		hWnd,
									   short	Method,
									   HANDLE	GrayImage,
									   LPHANDLE BWImage,
									   short	Parameter1,
									   float	Threshold);

extern int APIENTRY LSConvertImageToBWWithReport(HWND		hWnd,
												 short		Method,
												 HANDLE		GrayImage,
												 LPHANDLE	BWImage,
												 short		Parameter1,
												 float		Threshold,
												 int		*histogram,
												 int		*Noise,
												 int		*WhitePixel,
												 int		*BlackPixel);

extern int APIENTRY LSConvertImageResolution(HWND	hWnd,
											 HANDLE hImage,
											 int	NewResolution,
											 HANDLE *pImage);

extern int APIENTRY LSConvertImage200To100dpi(HWND		hWnd,
											  HANDLE	hImage,
											  HANDLE	*pImage);

extern int APIENTRY LSConvertImage200To254dpi(HWND		hWnd,
											  HANDLE	hImage,
											  HANDLE	*pImage);

extern int APIENTRY LSConvertImageColorTo256Gray(HWND	hWnd,
												 HANDLE	hImage,
												 HANDLE	*pImage256);

extern int APIENTRY LSConvertImage256To16Gray(HWND		hWnd,
											  HANDLE	hImage,
											  HANDLE	*pImage16);

extern int APIENTRY LSModifyPWMUltraViolet(short	hConnect,
										   HWND		hWnd,
										   short	Value,
										   BOOL		HighContrast,
										   short	Reserved);

extern int APIENTRY LSMergeImageGrayAndUV(HWND		hWnd,
										  HANDLE	hImageGray,
										  HANDLE	hImageUV,
										  float		Reserved1,
										  float		Reserved2,
										  HANDLE	*pImage);

extern int APIENTRY LSMergeImageColorAndUV(HWND		hWnd,
										   HANDLE	hImageColor,
										   HANDLE	hImageUV,
										   float	Reserved1,
										   float	Reserved2,
										   HANDLE	*pImage);

extern int APIENTRY LSConvertUVtoBWEx(HWND		hWnd,
									  HANDLE	hImageGray,
									  HANDLE	hImageUV,
									  float		Reserved1,
									  float		Reserved2,
									  int		UVImageType,
									  HANDLE	*pImage);

extern int APIENTRY LSConvertUVtoBW(HWND	hWnd,
									HANDLE	hImageGray,
									HANDLE	hImageUV,
									float	Reserved1,
									float	Reserved2,
									HANDLE	*pImage);

extern int APIENTRY LSSmoothingImage(HWND	hWnd,
									 HANDLE	hImage,
									 int	Reserved,
									 HANDLE	*pImage);

extern int APIENTRY LSRegionSpatialFilter(HWND		hWnd,
										  HANDLE	hImage,
										  short		Unit,
										  float		pos_x,
										  float		pos_y,
										  float		sizeW,
										  float		sizeH,
										  short		FilterType,
										  short		Reserved1,
										  short		Reserved2,
										  HANDLE	*pImage);

extern int APIENTRY LSFreeImage(HWND		hWnd,
								LPHANDLE	hImage);

extern int APIENTRY LSGetPresenceInkCartridge(short hConnect,
											  BOOL *fCartridge);

extern int APIENTRY LSLoadString(short	hConnect,
								 HWND	hWnd,
								 char	Format, 
								 short	Length,
								 LPSTR	String);

extern int APIENTRY LSLoadMixedString(short			hConnect,
									  HWND			hWnd,
									  unsigned long Reserved1,
									  short			Reserved2,
									  char	Font1, LPSTR String1, short Length1,
									  char	Font2, LPSTR String2, short Length2,
									  char	Font3, LPSTR String3, short Length3,
									  char	Font4, LPSTR String4, short Length4);

extern int APIENTRY LSLoadLogoToPrint(short				hConnect,
									  HWND				hWnd,
									  BITMAPINFOHEADER *pBmpLogo);

extern int APIENTRY LSLoadMultiStrings(short hConnect, HWND hWnd,
									   char Font1, LPSTR String1, short Length1,
									   char Font2, LPSTR String2, short Length2,
									   char Font3, LPSTR String3, short Length3,
									   char Font4, LPSTR String4, short Length4);

extern int APIENTRY LSLoadStringWithCounterEx(short			hConnect,
											  HWND			hWnd,
											  char			Format,
											  LPSTR			String,
											  short			Length,
											  unsigned long	StartNumber,
											  short			Step);

extern int APIENTRY LSLoadStringWithCounterLimit(short			hConnect,
												 HWND			hWnd,
												 char			Format,
												 LPSTR			String,
												 short			Length,
												 unsigned long	StartNumber,
												 short			Step,
												 unsigned long	Limit,
												 unsigned long	IniNumber);

extern int APIENTRY LSLoadDigitalStringWithCounter(short	hConnect,
												   HWND		hWnd,
												   char		Side,
												   char		*String,
												   short	llString,
												   unsigned long StartNumber,
												   short	Step,
												   char		*font,
												   int		dim,
												   BOOL		bold,
												   BOOL		italic,
												   BOOL		underline,
												   long		TextColor,
												   short	Unit,
												   float	pos_x,
												   float	pos_y);

extern int APIENTRY LSDigitalPrint(HWND		hWnd,
								   HANDLE	hImage,
								   char		*String,
								   short	llString,
								   char		*font,
								   int		dim,
								   BOOL		bold,
								   BOOL		italic,
								   BOOL		underline,
								   short	TextColor,
								   short	Unit,
								   float	pos_x,
								   float	pos_y);

extern int APIENTRY LSReadBadge(short	hConnect,
								HWND	hWnd,
								unsigned char Format,
								short	MaxLength,
								char	*String,
								short	*length);

extern int APIENTRY LSReadBadgeWithTimeout(short	hConnect,
										   HWND		hWnd,
										   unsigned char Format,
										   short	MaxLength,
										   char		*String,
										   short	*length,
										   long		Timeout);

extern int APIENTRY LSReset(short	hConnect,
							HWND	hWnd,
							char	ResetType);

extern int APIENTRY LSDisplayImage(HWND		hWnd,
								   HANDLE	hInstance,
								   char		*FilenameFront,
								   char		*FilenameBack,
								   int		XFront,
								   int		YFront,
								   int		XBack,
								   int		YBack,
								   int		FrontWidth,
								   int		FrontHeight,
								   int		BackWidth,
								   int		BackHeight,
								   HWND		*RetHwndFront,
								   HWND		*RetHwndBack);

extern int APIENTRY LSUpdateImage(HWND	hWnd,
								  char	*FilenameFront,
								  char	*FilenameBack,
								  HWND	hWndFront,
								  HWND	hWndBack);

extern int APIENTRY LSDisableWaitDocument(short hConnect,
										  HWND	hWnd,
										  BOOL	fWait);

extern int APIENTRY LSAutoDocHandle(short	hConnect,
									HWND	hWnd,
									short	Stamp,
									short	Validate,
									short	CodeLine,
									short	ScanMode,
									short	Feeder,
									short	Sorter,
									short	NumDocument,
									short	ClearBlack,
									char	Side,
									short	ScanDocType,
									short	SaveImage,
									char	*DirectoryFile,
									char	*BaseFilename,
									float	pos_x,
									float	pos_y,
									float	sizeW,
									float	sizeH,
									short	OriginMeasureDoc,
									short	OcrImageSide,
									short	FileFormat,
									int		Quality,
									int		SaveMode,
									int		PageNumber,
									short	WaitTimeout,
									short	Beep,
									int		(__stdcall *userfunc)(S_CODELINE_INFO *CodelineInfo),
									LPVOID	Reserved2,
									LPVOID	Reserved3);

extern int APIENTRY LSAutoDocHandleVB(short		hConnect,
									  HWND		hWnd,
									  short		Stamp,
									  short		Validate,
									  short		CodeLine,
									  short		ScanMode,
									  short		Feeder,
									  short		Sorter,
									  short		NumDocument,
									  short		ClearBlack,
									  char		Side,
									  short		ScanDocType,
									  short		SaveImage,
									  char		*DirectoryFile,
									  char		*BaseFilename,
									  float		pos_x,
									  float		pos_y,
									  float		sizeW,
									  float		sizeH,
									  short		OriginMeasureDoc,
									  short		OcrImageSide,
									  short		FileFormat,
									  int		Quality,
									  int		SaveMode,
									  int		PageNumber,
									  short		WaitTimeout,
									  short		Beep,
									  int		(__stdcall *userfunc)(S_CODELINE_INFO_VB *CodelineInfo),
									  LPVOID	Reserved2,
									  LPVOID	Reserved3);

extern int APIENTRY LS800AutoDocHandle( short	hConnect,
										HWND	hWnd,
										char	Validate,
										short	Codeline,
										char	Side,
										short	ScanModeFront,
										short	ScanModeBack,
										short	ClearBlack,
										short	NumDocument,
										short	SaveImage,
										char	*DirectoryFile,
										char	*BaseFilename,
										short	Unit,
										float	pos_x,
										float	pos_y,
										float	sizeW,
										float	sizeH,
										short	OcrImageSide,
										short	FileFormat,
										int		Quality,
										int		SaveMode,
										int		PageNumber,
										short	Beep,
										int		(__stdcall *userfunc1)(S_CODELINE_INFO_LS800 *CodelineInfo),
										int		(__stdcall *userfunc2)(S_IMAGE_INFO_LS800 *ImageInfo),
										int		(__stdcall *userfunc3)(S_IMAGE_INFO_LS800 *ImageInfo),
										short	Reserved1,		// not used must be NULL
										long	Reserved2,		// not used must be NULL
										LPVOID	Reserved3);		// not used must be NULL

extern int APIENTRY LS800AutoDocHandleVB(short	hConnect,
										HWND	hWnd,
										char	Validate,
										short	Codeline,
										char	Side,
										short	ScanModeFront,
										short	ScanModeBack,
										short	ClearBlack,
										short	NumDocument,
										short	SaveImage,
										char	*DirectoryFile,
										char	*BaseFilename,
										short	Unit,
										float	pos_x,
										float	pos_y,
										float	sizeW,
										float	sizeH,
										short	OcrImageSide,
										short	FileFormat,
										int		Quality,
										int		SaveMode,
										int		PageNumber,
										short	Beep,
										int		(__stdcall *userfunc1)(S_CODELINE_INFO_VB_LS800 *CodelineInfo),
										int		(__stdcall *userfunc2)(S_IMAGE_INFO_VB_LS800 *ImageInfo),
										int		(__stdcall *userfunc3)(S_IMAGE_INFO_VB_LS800 *ImageInfo),
										short	Reserved1,		// not used must be NULL
										long	Reserved2,		// not used must be NULL
										LPVOID	Reserved3);		// not used must be NULL

extern int APIENTRY LS800AutoDocHandleWithAllCallback(short	hConnect,
													  HWND	hWnd,
													  char	Validate,
													  short	Codeline,
													  char	Side,
													  short	ScanModeFront,
													  short	ScanModeBack,
													  short	ClearBlack,
													  short	NumDocument,
													  short	SaveImage,
													  char	*DirectoryFile,
													  char	*BaseFilename,
													  short	Unit,
													  float	pos_x,
													  float	pos_y,
													  float	sizeW,
													  float	sizeH,
													  short	OcrImageSide,
													  short	FileFormat,
													  int	Quality,
													  int	SaveMode,
													  int	PageNumber,
													  short	Beep,
													  short	SortOnChioce,
													  int	(*userfunc1)(S_CODELINE_INFO_LS800 *CodelineInfo),
													  int	(*userfunc2)(S_IMAGE_INFO_LS800 *ImageInfo),
													  int	(*userfunc3)(S_IMAGE_INFO_LS800 *ImageInfo),
													  short	Reserved1,
													  long	Reserved2,
													  LPVOID Reserved3);

extern int APIENTRY LSGetDocData(short			hConnect,
								 HWND			hWnd,
								 unsigned long	*NrDoc,
								 LPSTR			FilenameFront,
								 LPSTR			FilenameBack,
								 LPSTR			Reserved1,		// not used must be NULL
								 LPSTR			Reserved2,		// not used must be NULL
								 LPHANDLE		*FrontImage,
								 LPHANDLE		*BackImage,
								 LPHANDLE		*FrontImage2,	// not used must be NULL
								 LPHANDLE		*BackImage2,	// not used must be NULL
								 LPSTR			CodelineSW,
								 LPSTR			CodelineHW,
								 LPSTR			BarCode,
								 LPSTR			CodelinesOptical,
								 short			*DocToRead,
								 long			*NrPrinted,
								 LPVOID			Reserved5,		// not used must be NULL
								 LPVOID			Reserved6);		// not used must be NULL

extern int APIENTRY LSGetDocDataMH(short			hConnect,
								   HWND				hWnd,
								   unsigned long	*NrDoc,
								   LPSTR			FilenameFront,
								   LPSTR			FilenameBack,
								   LPSTR			FilenameFront2,
								   LPSTR			FilenameBack2,
								   LPHANDLE			*FrontImage,
								   LPHANDLE			*BackImage,
								   LPHANDLE			*FrontImage2,
								   LPHANDLE			*BackImage2,
								   LPSTR			CodelineSW,
								   LPSTR			CodelineHW,
								   LPSTR			BarCode,
								   LPSTR			CodelinesOptical,
								   short			*DocToRead,
								   long				*NrPrinted,
								   BOOL				VerifyHole,
								   short			Unit,
								   short			nrRegions,
								   MICROHOLE_STRUCT	*stMicroHole);

extern int APIENTRY LSStopAutoDocHandle(short	hConnect,
										HWND	hWnd);

extern int APIENTRY LSGetDocDataEx(short			hConnect,
								   HWND				hWnd,
								   int				CompressionPlace,
								   unsigned long	*NrDoc,
								   short			DpiImagesJPEG,
								   HANDLE			*FrontImageJPEG,
								   int				*SizeFrontImageJPEG,
								   HANDLE			*RearImageJPEG,
								   int				*SizeRearImageJPEG,
								   short			DpiImagesTIFF,
								   HANDLE			*FrontImageTIFF,
								   int				*SizeFrontTIFF,
								   HANDLE			*RearImageTIFF,
								   int				*SizeRearTIFF,
								   short			DpiImagesBMP,
								   HANDLE			*FrontImageBMP,
								   HANDLE			*RearImageBMP,
								   LPSTR			CodelineSW,
								   LPSTR			CodelineHW,
								   LPSTR			BarCode,
								   long				*NrPrinted,
								   int				TypeImageUV,
								   HANDLE			*FrontImageUV,
								   LPVOID			Reserved);

extern int APIENTRY LSPeripheralStatus(short			hConnect,
									   HWND				hWnd,
									   unsigned char	*SenseKey,
									   unsigned char	*StatusByte);

extern int APIENTRY LSSetUnitSpeed(short	hConnect,
								   HWND		hWnd,
								   short	UnitSpeed);

extern int APIENTRY LSGetVersion(char	*DllVersion,
								 short	LenString);

extern int APIENTRY LSFontDecodeVersion(char *DllVer,
										short LenD,
										char *FontVer,
										short LenF);

extern int APIENTRY LSChangeStampPosition(short		hConnect,
										  HWND		hWnd,
										  short		Step,
										  char		Reserved);

extern int APIENTRY LSViewOCRRectangle(HWND hWnd,
									   BOOL fView);

extern int APIENTRY LSBeep(short		  hConnect,
						   HWND			  hWnd,
						   short		  NrBeep,
						   unsigned short TimeOn,
						   unsigned short TimeOff);

extern int APIENTRY LSLED(short			 hConnect,
						  HWND			 hWnd,
						  short			 Color,
						  unsigned short TimeOn,
						  unsigned short TimeOff);

extern int APIENTRY LSHistoryCommand(short		hConnect,
									 HWND		hWnd,
									 short		Cmd,
									 void		*sHistory);

extern int APIENTRY LSDownloadFirmware(short	hConnect,
									   HWND		hWnd,
									   char		*FileFw,
									   int		(__stdcall *userfunc1)(char *Item));

extern int APIENTRY LSDownloadCTSModule(short	hConnect,
										char	*FileCTS,
										char	*PathFilenameDest,
										char	*Attrib,
										int		(__stdcall *userfunc1)(char *Item));

extern int APIENTRY LSReadWriteUnitMessage(short	hConnect,
										   HWND		hWnd,
										   short	Cmd,
										   short	*NrMsg,
										   short	*Blink,
										   unsigned char *pBuff);

extern int APIENTRY CTSLoadDIBimage(LPSTR filename, HANDLE *DibImage);

extern int APIENTRY CTSExtractColor(HANDLE hImage, short Color, HANDLE *pImage);

extern int APIENTRY CTSImageSize(HANDLE hImage, DWORD *ImageSize);

extern int APIENTRY CTSBase64decode(char *bufIn, short lenBufIn, char *bufOut, short lenBufOut);

extern int APIENTRY CTSSetCartridgeWarning(BOOL fDoWarning, long NrDotCartridge);

extern int APIENTRY LSEnableRangerTrace(int (*TraceFunc)(char *LogString));

extern int APIENTRY LSConnectDiagnostica(HWND, HANDLE, short, short *);

////////////////////////////////////////////////////////////////////
// FUNCTION MAINTAINED FOR BACKWARD COMPATIBILITY

extern int APIENTRY LSUnitIdentify(short	hConnect,
								   HWND		hWnd,
								   LPSTR	lpCfg,
								   LPSTR	LsModel,
								   LPSTR	Fw_Version,
								   LPSTR	Fw_Date,
								   LPSTR	PeripheralID,
								   LPSTR	BoardAndFPGANr,
								   LPSTR	DecoderExpVersion,
								   LPSTR	InkJetVersion,
								   LPSTR	FeederVersion,
								   LPSTR	SorterVersion,
								   LPSTR	MotorVersion,
								   LPSTR	Reserved1,
								   LPSTR	Reserved2);

extern int APIENTRY LSIdentifyEx(short	hConnect,
								 HWND	hWnd,
								 LPSTR	lpldPnt,
								 LPSTR	vendorModel,
								 LPSTR	productVersion,
								 LPSTR	DecoderExpVersion,
								 LPSTR	InkJetVersion,
								 LPSTR	SorterVersion,
								 LPSTR	MotorVersion,
								 LPSTR	Date_Fw,
								 LPSTR	PeripheralID,
								 LPSTR	Reserved2);

extern int APIENTRY LSIdentify(short	hConnect,
							   HWND		hWnd,
							   LPSTR	lpldPnt,
							   LPSTR	vendorModel,
							   LPSTR	productVersion,
							   LPSTR	DecoderExpVersion,
							   LPSTR	InkJetVersion,
							   LPSTR	SorterVersion,
							   LPSTR	MotorVersion);

extern int APIENTRY LSConfigDoubleLeafingEx(short	hConnect,
											HWND	hWnd,
											long	Type,
											short	Value,
											long	Reserved);

extern int APIENTRY LSDoubleLeafingSensibility(short			hConnect,
											   HWND				hWnd,
											   short			Reserved,
											   unsigned char	Value);

extern int APIENTRY LSConfigDoubleLeafing(short		hConnect,
										  HWND		hWnd,
										  short		Value);

extern int APIENTRY LSLoadStringWithCounter(short			hConnect,
											HWND			hWnd,
											char			Format,
											LPSTR			String,
											unsigned long	StartNumber,
											short			Step);

extern int APIENTRY LSReadPdf417FromBitmap(HWND		hWnd,
										   HANDLE	hImage,
										   LPSTR	Codeline,
										   UINT		*Length,
										   char		*ErrorRate,
										   int		Reserved1,
										   int		Reserved2,
										   int		Reserved3,
										   int		Reserved4);

extern int APIENTRY LSSaveTIFF(HWND		hWnd,
							   HANDLE	hImage,
							   LPSTR	filename,
							   int		Type,
							   int		SaveMode,
							   int		PageNumber);

extern int APIENTRY LSRotateImage(HWND		hWnd,
								  HANDLE	hImage,
								  int		degree,
								  HANDLE	*pImage);

extern int APIENTRY LSDocHandleAndGetData(short			hConnect,
										  HWND			hWnd,
										  short			Stamp,
										  short			Validate,
										  short			CodeLine,
										  short			Feeder,
										  short			Sorter,
										  short			ScanMode,
										  short			ClearBlack,
										  char			Side,
										  short			ReadMode,
										  short			SaveImage,
										  char			*DirectoryFile,
										  char			*BaseFilename,
										  int			pos_x,
										  int			pos_y,
										  int			sizeW,
										  int			sizeH,
										  short			OcrImageSide,
										  int			Quality,
										  short			FileFormat,
										  short			WaitTimeout,
										  short			Beep,
										  int			SaveMode,
										  int			PageNumber,
										  short			Reserved1,
										  LPVOID		Reserved2,

										  unsigned long	*NrDoc,
										  LPSTR			FilenameFront,
										  LPSTR			FilenameBack,
										  LPSTR			Reserved3,		// immagine Fronte NETTO
										  LPSTR			Reserved4,		// immagine Retro NETTO
							  			  LPLONG		*FrontImage,
									  	  LPLONG		*BackImage,
									  	  LPLONG		*Reserved5,		// immagine Fronte NETTO
									  	  LPLONG		*Reserved6,		// immagine Retro NETTO
									  	  LPSTR			CodelineSW,
							  			  LPSTR			CodelineHW,
									  	  LPSTR			BarCode,
									  	  LPSTR			CodelinesOptical,
										  LPVOID		Reserved7,		// not used must be NULL
										  LPVOID		Reserved8);		// not used must be NULL

extern int APIENTRY LSDocHandleOverlapped(short		hConnect,
										  HWND		hWnd,
										  short		Stamp,
										  short		Validate,
										  short		CodeLine,
										  char		Side,
										  short		ScanMode,
										  short		ClearBlack,
										  short		WaitTimeout,
										  short		Beep,
										  short		NumDocument,
										  short		Reserved1,
										  long		Reserved2,
										  int		(__stdcall *userfunc1)(S_CODELINE_INFO_LS100 *CodelineInfo),
										  int		(__stdcall *userfunc2)(S_IMAGE_INFO_LS100 *ImageInfo),
										  int		(__stdcall *userfunc3)(S_IMAGE_INFO_LS100 *ImageInfo),
										  void		*Reserved3);

////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif




////////////////////////////////////////////////////////////////////
// SECTION FOR PDF DOCUMENTS

// ------------------------------------------------------------------------
//		Defines and Struct for save images as PDF/A documents
// ------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern int APIENTRY LSPDFASetMetadata(HWND hWnd, char *szKey, char *szValue);

extern int APIENTRY LSPDFADeleteMetadata(HWND hWnd, char *szKey);

extern int APIENTRY LSPDFASaveDoc(short		hConnect,
								  HWND		hWnd,
								  char		*DocFilename,
								  short		TypeDocPDF,
								  HANDLE	pImageFront,
								  long		sizeImageFront,
								  HANDLE	pImageRear,
								  long		sizeImageRear);

#ifdef __cplusplus
}
#endif

// SECTION FOR IMAGE SIGNATURE
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
// SECTION FOR IMAGE SIGNATURE

// ------------------------------------------------------------------------
//		Defines and Struct for signature image
// ------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern int APIENTRY LSSetSignatureKey(short			hConnect,
									  HWND			hWnd,
									  unsigned char *Key,
									  short			lenKey,
									  BOOL			Reserved);

// Function for check the image integrity
extern int APIENTRY CTSCheckImageSignature(unsigned char	*nFile,
										   unsigned char	*Key,
										   short			LenKey,
										   unsigned char	*SerialNr);

extern int APIENTRY CTSCheckSignature(unsigned char *pImage,
									  long			LenImage,
									  char			*Key,
									  short			LenKey,
									  unsigned char *SerialNr);

extern int APIENTRY LSWriteCertificate(short			hConnect,
									   HWND				hWnd,
									   unsigned char	*pCertificate,
									   long				nrBytesCert);

extern int APIENTRY LSReadCertificate(short				hConnect,
									  HWND				hWnd,
									  unsigned char		*pCertificate,
									  long				*nrBytesCert);

#ifdef __cplusplus
}
#endif

// SECTION FOR IMAGE SIGNATURE
////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////
// SECTION FOR CHECK IMAGE QUALITY ASSURANCE

// ------------------------------------------------------------------------
//		Defines and Struct for CTS IQA certification
// ------------------------------------------------------------------------
// TriState Flag
enum
{
	CONDITION_FLAG_NO_TESTED,
	CONDITION_FLAG_DEFECT_PRESENT,
	CONDITION_FLAG_DEFECT_NOT_PRESENT
};


//-----------------------------------------------------------------
//			Reply Code Functions
//-----------------------------------------------------------------
#define CTSIQA_OKAY                                            0

//-----------------------------------------------------------------
//			Reply Code Errors
//-----------------------------------------------------------------
#define CTSIQA_ERROR_ON_READ_INI_FILE						-2001
#define CTSIQA_DOCTYPE_NOT_CONFIGURED						-2002
#define CTSIQA_TEST_NOT_CONFIGURED							-2003
#define CTSIQA_MISSING_IMAGE								-2004
#define CTSIQA_INVALID_SIDE									-2005
#define CTSIQA_IMAGE_NOT_CONFORMED							-2006
#define CTSIQA_INVALID_COLOR								-2007
#define CTSIQA_INCOMPATIBLE_IMAGE							-2008
#define CTSIQA_DEFECT_EDGE_BOTTOM							-2009
#define CTSIQA_DEFECT_EDGE_TOP								-2010
#define CTSIQA_DEFECT_EDGE_LEFT								-2011
#define CTSIQA_DEFECT_EDGE_RIGHT							-2012
#define CTSIQA_DEFECT_CORNER_LOWERLEFT						-2013
#define CTSIQA_DEFECT_CORNER_LOWERRIGHT						-2014
#define CTSIQA_DEFECT_CORNER_UPPERLEFT						-2015
#define CTSIQA_DEFECT_CORNER_UPPERRIGHT						-2016
#define CTSIQA_DEFECT_BOTTOM_EDGE_HORIZONTALSCANLINES		-2017
#define CTSIQA_DEFECT_TOP_EDGE_HORIZONTALSCANLINES			-2018
#define CTSIQA_DEFECT_LEFT_EDGE_VERTICAL_SCANLINEWIDTH		-2019
#define CTSIQA_DEFECT_RIGHT_EDGE_VERTICAL_SCANLINEWIDTH		-2020
#define CTSIQA_STRING_TRUNCATED								-2021
#define CTSIQA_ILLEGAL_USE									-2022
#define CTSIQA_SESSION_NOT_CONFIGURED 						-2023
#define CTSIQA_INVALID_RESOLUTION							-2024


//-----------------------------------------------------------------
//			Reply Code on load file CtsIqa.ini
//-----------------------------------------------------------------
#define CTSIQA_ERROR_TO_OPEN_INI_FILE						-2101
#define CTSIQA_ERROR_ON_SYNTAX_LINE							-2102
#define CTSIQA_ERROR_MISSING_DOCTYPE_VALUE        			-2103
#define CTSIQA_ERROR_ON_SYNTAX_SECTION						-2104



// IQA struct function reply
typedef struct IqaTestError
{
	long	Size ;
	long	Function_Paramiter_Error ;
	long	Undersize_Image_flag;
	long	Undersize_Image_error;
	long	Undersize_Image_Width ;
	long	Undersize_Image_Height ;
	long	Document_Corners_flag ;
	long	Document_Corners_error ;
	long	Document_Corners_width ;
	long	Document_Corners_height ;
	long	Document_Edges_flag;
	long	Document_Edges_error ;
	long	Document_Edges_width ;
	long	Document_Edges_height ;
	long	Document_Framing_flag ;
	long	Document_Framing_error ;
	long	Document_Framing_left ;
	long	Document_Framing_right;
	long	Document_Framing_top;
	long	Document_Framing_bottom ;
	long	Document_Skew_flag ;
	long	Document_Skew_error ;
	long	Document_Skew_value ;
	long	Oversize_Image_flag ;
	long	Oversize_Image_error ;
	long	Oversize_Image_Width ;
	long	Oversize_Image_Height ;
	long	Image_too_Light_flag ;
	long	Image_too_Light_error ;
	long	Image_too_Light_AvgBrightness ;
	long	Image_too_Light_AvgContrast ;
	long	Image_too_Light_PercentBlackPixel ;
	long	Image_too_Dark_flag ;
	long	Image_too_Dark_error ;
	long	Image_too_Dark_AvgBrightness;
	long	Image_too_Dark_PercentBlackPixel ;
	long	Horizontal_Streaks_flag ;
	long	Horizontal_Streaks_error ;
	long	Horizontal_Streaks_value ;
	long	Below_Compressed_Size_flag ;
	long	Below_Compressed_Size_error ;
	long	Below_Compressed_Size_value ;
	long	Above_Compressed_Size_flag ;
	long	Above_Compressed_Size_error ;
	long	Above_Compressed_Size_value ;
	long	Spot_Noise_flag ;
	long	Spot_Noise_error ;
	long	Spot_Noise_value ;
	long	Front_Rear_Dimension_Mismatch_flag;
	long	Front_Rear_Dimension_Mismatch_error ;
	long	Front_Rear_Dimension_Mismatch_widthdiff ;
	long	Front_Rear_Dimension_Mismatch_heightdiff ;
	long	Carbon_Strip_flag ;
	long	Carbon_Strip_error ;
	long	Out_of_Focus_flag ;
	long	Out_of_Focus_error ;
	long	Out_of_Focus_value ;

} CTSIQA_TESTS_ERRORS;

// ------------------------------------------------------------------------
//		End Defines and Struct for CTS IQA certification
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
//		Api's functions for CTS IQA certification
// ------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

extern int APIENTRY LSIQACheckImage(HWND	hWnd,
									int		DocType,
									HANDLE	pImageFront,
									HANDLE	pImageRear,
									char	*pFilenameFrontCompressed,
									char	*pFilenameRearCompressed);

extern int APIENTRY LSIQACheckImageMemory(HWND		hWnd,
										  int		DocType,
										  HANDLE	pImageFront,
										  HANDLE	pImageRear,
										  char		*pFrontCompressed,
										  long		DimFrontCompressed,
										  char		*pRearCompressed,
										  long		DimRearCompressed);

extern int APIENTRY LSIQAgetLoadIniError(HWND	hWnd,
										 char	*DetailError,
										 long	llString);

extern int APIENTRY LSIQAGetTestsErrors(HWND				 hWnd,
										CTSIQA_TESTS_ERRORS *stTestErrorsFront,
										CTSIQA_TESTS_ERRORS *stTestErrorsRear);

extern int APIENTRY LSIQALibraryVersion(char *VersionLibrary,
										short LengthStr);

////////////////////////////////////////////////////////////////////


#ifdef __cplusplus
}
#endif

////////////////////////////////////////////////////////////////////

#endif