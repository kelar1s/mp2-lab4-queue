#pragma once
#include "../Queue/Queue.h"
#include <math.h>
#include <random>

namespace VisualQueueWork {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    private:
        TQueue<int>* q;
        int addedCount;
        int removedCount;
        int initialCount;
       
        double addChance;
        double removeChance;

        int updateFrequency;

        int X = 165;
        int Y = 85;
        int WIDTH = 200;
        int HEIGHT = 200;

        Random^ MyRand = gcnew Random();
    private: System::Windows::Forms::Label^ lblError;
        int hasStarted = 0;

        void Draw()
        {
            Pen^ MyPen = gcnew Pen(Color::Black);
            MyPen->Width = 15.0F;
            Graphics^ gr = this->CreateGraphics();

            int Start = 360 * q->GetHead() / q->GetMaxSize();
            int Finish = 360 * q->GetCurrentSize() / q->GetMaxSize();
            
            gr->DrawArc(MyPen, X, Y, WIDTH, HEIGHT, Start, Finish);
        }

        void Clear()
        {
            Pen^ MyPen = gcnew Pen(Color::Gray);
            MyPen->Width = 15.0F;
            Graphics^ gr = this->CreateGraphics();

            int Start = 360 * q->GetHead() / q->GetMaxSize();
            int Finish = 360 * q->GetCurrentSize() / q->GetMaxSize();
            
            gr->DrawArc(MyPen, X, Y, WIDTH, HEIGHT, Start, Finish);
        }
    public:
        MainForm(void)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
        }

    protected:

        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    protected:
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ txtMaxSize;
    private: System::Windows::Forms::TextBox^ txtInitialCount;
    private: System::Windows::Forms::TextBox^ txtAddChance;
    private: System::Windows::Forms::TextBox^ txtRemoveChance;
    private: System::Windows::Forms::TextBox^ txtUpdateFrequency;
    private: System::Windows::Forms::Button^ btnStart;
    private: System::Windows::Forms::Button^ btnStop;
    private: System::Windows::Forms::Button^ btnReset;
    private: System::Windows::Forms::Label^ lblAdded;
    private: System::Windows::Forms::Label^ lblRemoved;
    private: System::Windows::Forms::Label^ lblCurrentSize;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->txtMaxSize = (gcnew System::Windows::Forms::TextBox());
            this->txtInitialCount = (gcnew System::Windows::Forms::TextBox());
            this->txtAddChance = (gcnew System::Windows::Forms::TextBox());
            this->txtRemoveChance = (gcnew System::Windows::Forms::TextBox());
            this->txtUpdateFrequency = (gcnew System::Windows::Forms::TextBox());
            this->btnStart = (gcnew System::Windows::Forms::Button());
            this->btnStop = (gcnew System::Windows::Forms::Button());
            this->btnReset = (gcnew System::Windows::Forms::Button());
            this->lblAdded = (gcnew System::Windows::Forms::Label());
            this->lblRemoved = (gcnew System::Windows::Forms::Label());
            this->lblCurrentSize = (gcnew System::Windows::Forms::Label());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->lblError = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(12, 346);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(161, 22);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Max Queue Size:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->Location = System::Drawing::Point(12, 379);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(403, 22);
            this->label2->TabIndex = 1;
            this->label2->Text = L"The initial number of elements in the queue:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->Location = System::Drawing::Point(12, 415);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(173, 22);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Chance of adding:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label4->Location = System::Drawing::Point(12, 451);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(176, 22);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Extraction chance:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label5->Location = System::Drawing::Point(12, 493);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(174, 22);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Update frequency:";
            // 
            // txtMaxSize
            // 
            this->txtMaxSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->txtMaxSize->Location = System::Drawing::Point(432, 343);
            this->txtMaxSize->Name = L"txtMaxSize";
            this->txtMaxSize->Size = System::Drawing::Size(100, 27);
            this->txtMaxSize->TabIndex = 5;
            // 
            // txtInitialCount
            // 
            this->txtInitialCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->txtInitialCount->Location = System::Drawing::Point(432, 379);
            this->txtInitialCount->Name = L"txtInitialCount";
            this->txtInitialCount->Size = System::Drawing::Size(100, 27);
            this->txtInitialCount->TabIndex = 6;
            // 
            // txtAddChance
            // 
            this->txtAddChance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->txtAddChance->Location = System::Drawing::Point(432, 412);
            this->txtAddChance->Name = L"txtAddChance";
            this->txtAddChance->Size = System::Drawing::Size(100, 27);
            this->txtAddChance->TabIndex = 7;
            // 
            // txtRemoveChance
            // 
            this->txtRemoveChance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->txtRemoveChance->Location = System::Drawing::Point(432, 448);
            this->txtRemoveChance->Name = L"txtRemoveChance";
            this->txtRemoveChance->Size = System::Drawing::Size(100, 27);
            this->txtRemoveChance->TabIndex = 8;
            // 
            // txtUpdateFrequency
            // 
            this->txtUpdateFrequency->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->txtUpdateFrequency->Location = System::Drawing::Point(432, 490);
            this->txtUpdateFrequency->Name = L"txtUpdateFrequency";
            this->txtUpdateFrequency->Size = System::Drawing::Size(100, 27);
            this->txtUpdateFrequency->TabIndex = 9;
            // 
            // btnStart
            // 
            this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnStart->Location = System::Drawing::Point(49, 531);
            this->btnStart->Name = L"btnStart";
            this->btnStart->Size = System::Drawing::Size(88, 42);
            this->btnStart->TabIndex = 10;
            this->btnStart->Text = L"Start";
            this->btnStart->UseVisualStyleBackColor = true;
            this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
            // 
            // btnStop
            // 
            this->btnStop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnStop->Location = System::Drawing::Point(221, 531);
            this->btnStop->Name = L"btnStop";
            this->btnStop->Size = System::Drawing::Size(88, 42);
            this->btnStop->TabIndex = 11;
            this->btnStop->Text = L"Pause";
            this->btnStop->UseVisualStyleBackColor = true;
            this->btnStop->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
            // 
            // btnReset
            // 
            this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnReset->Location = System::Drawing::Point(396, 531);
            this->btnReset->Name = L"btnReset";
            this->btnReset->Size = System::Drawing::Size(88, 42);
            this->btnReset->TabIndex = 12;
            this->btnReset->Text = L"Reset";
            this->btnReset->UseVisualStyleBackColor = true;
            this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
            // 
            // lblAdded
            // 
            this->lblAdded->AutoSize = true;
            this->lblAdded->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblAdded->Location = System::Drawing::Point(-1, 9);
            this->lblAdded->Name = L"lblAdded";
            this->lblAdded->Size = System::Drawing::Size(73, 22);
            this->lblAdded->TabIndex = 13;
            this->lblAdded->Text = L"Added:";
            // 
            // lblRemoved
            // 
            this->lblRemoved->AutoSize = true;
            this->lblRemoved->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblRemoved->Location = System::Drawing::Point(155, 9);
            this->lblRemoved->Name = L"lblRemoved";
            this->lblRemoved->Size = System::Drawing::Size(99, 22);
            this->lblRemoved->TabIndex = 14;
            this->lblRemoved->Text = L"Removed:";
            // 
            // lblCurrentSize
            // 
            this->lblCurrentSize->AutoSize = true;
            this->lblCurrentSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblCurrentSize->Location = System::Drawing::Point(346, 9);
            this->lblCurrentSize->Name = L"lblCurrentSize";
            this->lblCurrentSize->Size = System::Drawing::Size(124, 22);
            this->lblCurrentSize->TabIndex = 15;
            this->lblCurrentSize->Text = L"Current size:";
            // 
            // timer1
            // 
            this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
            // 
            // lblError
            // 
            this->lblError->AutoSize = true;
            this->lblError->BackColor = System::Drawing::SystemColors::ScrollBar;
            this->lblError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblError->ForeColor = System::Drawing::SystemColors::WindowText;
            this->lblError->Location = System::Drawing::Point(193, 596);
            this->lblError->Name = L"lblError";
            this->lblError->Size = System::Drawing::Size(0, 24);
            this->lblError->TabIndex = 16;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(551, 630);
            this->Controls->Add(this->lblError);
            this->Controls->Add(this->lblCurrentSize);
            this->Controls->Add(this->lblRemoved);
            this->Controls->Add(this->lblAdded);
            this->Controls->Add(this->btnReset);
            this->Controls->Add(this->btnStop);
            this->Controls->Add(this->btnStart);
            this->Controls->Add(this->txtUpdateFrequency);
            this->Controls->Add(this->txtRemoveChance);
            this->Controls->Add(this->txtAddChance);
            this->Controls->Add(this->txtInitialCount);
            this->Controls->Add(this->txtMaxSize);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"MainForm";
            this->Text = L"Queue Ring";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        timer1->Enabled = false;
    }
    private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
        lblError->Text = "";
        if (txtMaxSize->Text == "" || txtAddChance->Text == "" || txtRemoveChance->Text == "" || txtUpdateFrequency->Text == "" || txtInitialCount->Text == "") {
            lblError->Text = "Error: Fill in all fields!";
            return;
        }
        addChance = Convert::ToDouble(txtAddChance->Text);
        removeChance = Convert::ToDouble(txtRemoveChance->Text);
        initialCount = Convert::ToInt32(txtInitialCount->Text);
        updateFrequency = Convert::ToInt32(txtUpdateFrequency->Text);
        if (hasStarted == 0)
        {
            Pen^ MyPen = gcnew Pen(Color::Gray);
            MyPen->Width = 15.0F;
            Graphics^ gr = this->CreateGraphics();
            gr->DrawArc(MyPen, X, Y, WIDTH, HEIGHT, 360, 360);
            timer1->Interval = updateFrequency;
            int MaxSize = Convert::ToInt32(txtMaxSize->Text);
            q = new TQueue<int>(MaxSize);
            hasStarted = 1;
            if (initialCount != 0) {
                for (int i = 0; i < initialCount; i++)
                {
                    q->push(1);
                }
            }
            else {
                for (int i = 0; i < 15; i++)
                {
                    q->push(1);
                }
            }
        }
        timer1->Enabled = true;
    }

    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!q->isEmpty() && !q->isFull())
            {
                Clear();
            }
            if (MyRand->Next(0, 101) < addChance)
            {
                q->push(1);
                addedCount++;
            }
            if (MyRand->Next(0, 101) < removeChance)
            {
                q->pop();
                removedCount++;
            }
            Draw();
            lblAdded->Text = "Added: " + Convert::ToString(addedCount);
            lblRemoved->Text = "Removed: " + Convert::ToString(removedCount);
            lblCurrentSize->Text = "Current Size: " + Convert::ToString(q->GetCurrentSize());
        }
        catch (const std::exception& ex) {
            lblError->Text = gcnew String(ex.what());
            timer1->Enabled = false;
        }
        
    }
    private: System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {
        lblError->Text = "";
        timer1->Enabled = false;
        Clear();
        delete q;
        hasStarted = 0;
        addedCount = 0;
        removedCount = 0;
        lblAdded->Text = "Added: " + Convert::ToString(0);
        lblRemoved->Text = "Removed: " + Convert::ToString(0);
        lblCurrentSize->Text = "Current Size: " + Convert::ToString(0);
    }
    };
}
