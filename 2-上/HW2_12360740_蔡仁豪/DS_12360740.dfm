object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 726
  ClientWidth = 974
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 32
    Top = 40
    Width = 305
    Height = 497
    ActivePage = TabSheet1
    TabOrder = 0
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #25490#24207
      object Label1: TLabel
        Left = 16
        Top = 16
        Width = 140
        Height = 37
        Caption = #36664#20837#38263#24230#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 19
        Top = 354
        Width = 85
        Height = 21
        Caption = #22266#23450#38263#24230#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 83
        Top = 62
        Width = 54
        Height = 21
        Caption = #38263#24230'<9'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 19
        Top = 152
        Width = 140
        Height = 37
        Caption = #36664#20837#23383#20018#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 165
        Top = 16
        Width = 108
        Height = 45
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '3'
      end
      object Edit2: TEdit
        Left = 110
        Top = 351
        Width = 49
        Height = 29
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '0'
      end
      object Button1: TButton
        Left = 19
        Top = 89
        Width = 193
        Height = 41
        Caption = #29983#25104#25490#24207
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button1Click
      end
      object CheckBox1: TCheckBox
        Left = 181
        Top = 359
        Width = 84
        Height = 17
        Caption = #39023#31034#27493#39519
        TabOrder = 5
      end
      object Edit3: TEdit
        Left = 19
        Top = 211
        Width = 254
        Height = 45
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = 'ABCXYZ'
      end
      object Button2: TButton
        Left = 16
        Top = 280
        Width = 193
        Height = 41
        Caption = #29983#25104#25490#24207
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #27827#20839#22612
      ImageIndex = 1
      object Label5: TLabel
        Left = 16
        Top = 32
        Width = 84
        Height = 37
        Caption = #23652#25976#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object Edit4: TEdit
        Left = 106
        Top = 29
        Width = 121
        Height = 45
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '3'
      end
      object Button3: TButton
        Left = 16
        Top = 104
        Width = 177
        Height = 49
        Caption = #38283#22987#31227#21205
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button3Click
      end
      object CheckBox2: TCheckBox
        Left = 199
        Top = 136
        Width = 82
        Height = 17
        Caption = #35264#30475#21205#30059
        TabOrder = 2
      end
    end
  end
  object PageControl2: TPageControl
    Left = 360
    Top = 40
    Width = 585
    Height = 497
    ActivePage = TabSheet3
    TabOrder = 1
    object TabSheet3: TTabSheet
      Caption = #25490#24207
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 577
        Height = 467
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          #25490#24207#65306)
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitLeft = -56
        ExplicitTop = -26
      end
    end
    object TabSheet4: TTabSheet
      Caption = #25490#24207#36942#31243
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 577
        Height = 467
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          #25490#24207#36942#31243#65306)
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitTop = 3
        ExplicitHeight = 464
      end
    end
  end
  object PageControl3: TPageControl
    Left = 360
    Top = 40
    Width = 589
    Height = 497
    ActivePage = TabSheet5
    TabOrder = 2
    Visible = False
    object TabSheet5: TTabSheet
      Caption = #31227#21205#27493#39519
      object PaintBox1: TPaintBox
        Left = 0
        Top = 296
        Width = 581
        Height = 171
        Align = alBottom
      end
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 581
        Height = 296
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          #31227#21205#27493#39519#65306)
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
end
