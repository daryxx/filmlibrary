object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
  ClientHeight = 556
  ClientWidth = 1527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 206
    Height = 31
    Alignment = taCenter
    Caption = #1053#1072#1081#1076#1077#1085#1086' '#1092#1080#1083#1100#1084#1086#1074':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 408
    Top = 24
    Width = 13
    Height = 31
    Alignment = taCenter
    Caption = '0'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI Semibold'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Button1: TButton
    Left = 1353
    Top = 499
    Width = 145
    Height = 38
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 61
    Width = 1474
    Height = 417
    ColCount = 8
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ColWidths = (
      64
      386
      271
      264
      68
      108
      124
      176)
    RowHeights = (
      24
      30)
  end
  object SaveDialog1: TSaveDialog
    Left = 32
    Top = 496
  end
  object SaveDialog2: TSaveDialog
    Left = 104
    Top = 496
  end
end
