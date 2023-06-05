object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100
  ClientHeight = 618
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -23
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCloseQuery = FormCloseQuery
  TextHeight = 31
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 100
    Height = 31
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077
  end
  object Label2: TLabel
    Left = 40
    Top = 99
    Width = 103
    Height = 31
    Caption = #1056#1077#1078#1080#1089#1089#1077#1088
  end
  object Label3: TLabel
    Left = 40
    Top = 168
    Width = 161
    Height = 31
    Caption = #1042' '#1075#1083#1072#1074#1085#1086#1081' '#1088#1086#1083#1080
  end
  object Label4: TLabel
    Left = 40
    Top = 232
    Width = 129
    Height = 31
    Caption = #1043#1086#1076' '#1074#1099#1087#1091#1089#1082#1072
  end
  object Label5: TLabel
    Left = 40
    Top = 299
    Width = 144
    Height = 31
    Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
  end
  object Label6: TLabel
    Left = 40
    Top = 370
    Width = 59
    Height = 31
    Caption = #1046#1072#1085#1088
  end
  object Label7: TLabel
    Left = 40
    Top = 451
    Width = 140
    Height = 31
    Caption = #1042#1080#1076' '#1085#1086#1089#1080#1090#1077#1083#1103
  end
  object Label8: TLabel
    Left = 650
    Top = 304
    Width = 47
    Height = 31
    Caption = #1084#1080#1085'.'
  end
  object Button1: TButton
    Left = 472
    Top = 544
    Width = 225
    Height = 41
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 248
    Top = 29
    Width = 449
    Height = 39
    TabOrder = 1
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 248
    Top = 96
    Width = 449
    Height = 39
    TabOrder = 2
    OnKeyPress = Edit1KeyPress
  end
  object Edit3: TEdit
    Left = 248
    Top = 165
    Width = 449
    Height = 39
    TabOrder = 3
    OnKeyPress = Edit1KeyPress
  end
  object ListBox1: TListBox
    Left = 248
    Top = 360
    Width = 449
    Height = 61
    ItemHeight = 31
    Items.Strings = (
      #1050#1086#1084#1077#1076#1080#1103
      #1060#1072#1085#1090#1072#1089#1090#1080#1082#1072
      #1060#1101#1085#1090#1077#1079#1080
      #1041#1083#1086#1082#1073#1072#1089#1090#1077#1088
      #1058#1088#1080#1083#1083#1077#1088
      #1040#1085#1080#1084#1072#1094#1080#1103
      #1044#1088#1072#1084#1072
      #1044#1077#1090#1077#1082#1090#1080#1074
      #1059#1078#1072#1089#1099
      #1044#1088#1091#1075#1086#1077)
    TabOrder = 6
    OnKeyPress = Edit1KeyPress
  end
  object ListBox2: TListBox
    Left = 248
    Top = 443
    Width = 449
    Height = 62
    ItemHeight = 31
    Items.Strings = (
      'Dvd'
      #1050#1072#1089#1089#1077#1090#1072
      'Flash-'#1085#1072#1082#1086#1087#1080#1090#1077#1083#1100
      'Hdd'
      #1054#1073#1083#1072#1082#1086
      #1044#1088#1091#1075#1086#1077)
    TabOrder = 7
    OnKeyPress = Edit1KeyPress
  end
  object MaskEdit1: TMaskEdit
    Left = 248
    Top = 229
    Width = 445
    Height = 39
    EditMask = '9000;1;_'
    MaxLength = 4
    TabOrder = 4
    Text = '    '
    OnKeyPress = Edit1KeyPress
  end
  object Edit4: TEdit
    Left = 248
    Top = 296
    Width = 396
    Height = 39
    NumbersOnly = True
    TabOrder = 5
    OnKeyPress = Edit1KeyPress
  end
end
